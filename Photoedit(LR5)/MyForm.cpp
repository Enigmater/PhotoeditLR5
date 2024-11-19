#include "MyForm.h"
#include <math.h>

System::Void PhotoeditLR5::MyForm::button_openFile_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Создаем и показываем диалог выбора файла
    OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
    openFileDialog->Filter = "Изображения|*.bmp;*.jpg;*.jpeg;*.png;*.gif;*.tiff|Все файлы|*.*";
    openFileDialog->Title = "Выберите изображение";

    // Если пользователь выбрал файл, загружаем его
    if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        try {
            // Загружаем изображение по выбранному пути
            image = gcnew Bitmap(openFileDialog->FileName);
            startImage = gcnew Bitmap(image);
            panel_image->Invalidate(); // Перерисовываем groupBox, чтобы отобразить изображение
        }
        catch (Exception^ ex) {
            MessageBox::Show("Ошибка загрузки изображения: " + ex->Message);
        }
    }
}

// Начало выделения области
System::Void PhotoeditLR5::MyForm::panel_image_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    if (e->Button == System::Windows::Forms::MouseButtons::Left) {
        isSelecting = true;
        if (startImage) image = gcnew Bitmap(startImage);
        this->panel_image->Invalidate();
        selectionStart = e->Location;
    }
}

// Завершение выделения области
System::Void PhotoeditLR5::MyForm::panel_image_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    if (e->Button == System::Windows::Forms::MouseButtons::Left) {
        isSelecting = false;
        ApplyAdjust(selectionRectangle);
    }
}

// Выделение области
System::Void PhotoeditLR5::MyForm::panel_image_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    if (isSelecting) {
        int x = Math::Min(e->X, selectionStart.X);
        int y = Math::Min(e->Y, selectionStart.Y);
        int width = Math::Abs(e->X - selectionStart.X);
        int height = Math::Abs(e->Y - selectionStart.Y);

        selectionRectangle = Rectangle(x, y, width, height);
        this->panel_image->Invalidate();
    }
}

void PhotoeditLR5::MyForm::ApplyAdjust(Rectangle rect)
{
    if (image && selectionRectangle.Width > 0 && selectionRectangle.Height > 0) {
        image = gcnew Bitmap(startImage);
        int brightness = trackBar_brightnrss->Value;
        int contrast = trackBar_contrast->Value / 100.0f;

        AdjustBrightness(rect, brightness);
        AdjustContrast(rect, contrast);

        this->panel_image->Invalidate();
    }
}

System::Void PhotoeditLR5::MyForm::panel_image_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
    // Если изображение загружено, рисуем его на форме
    if (image != nullptr) {
        panel_image->Width = image->Width;
        panel_image->Height = image->Height;
        e->Graphics->DrawImage(image, 0, 0, panel_image->ClientSize.Width, panel_image->ClientSize.Height);
    }

    // Рисуем прямоугольник выделенной области, если он существует
    if (selectionRectangle.Width > 0 && selectionRectangle.Height > 0) {
        Drawing::Pen^ pen = gcnew Pen(Color::Blue, 1);
        e->Graphics->DrawRectangle(pen, selectionRectangle);
    }
}

System::Void PhotoeditLR5::MyForm::trackBar_brightnrss_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    ApplyAdjust(this->selectionRectangle);
}

System::Void PhotoeditLR5::MyForm::trackBar_contrast_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    ApplyAdjust(this->selectionRectangle);
}

void PhotoeditLR5::MyForm::AdjustBrightness(Rectangle rect, int brightness)
{
    // Работаем с пикселями внутри выделенной области
    for (int x = rect.Left; x < rect.Right; x++) {
        for (int y = rect.Top; y < rect.Bottom; y++) {
            // Проверяем, не выходит ли координата за пределы изображения
            if (x < 0 || x >= image->Width || y < 0 || y >= image->Height)
                continue;

            // Получаем цвет пикселя на изображении
            Color pixelColor = image->GetPixel(x, y);

            // Получаем компоненты цвета
            int r = pixelColor.R + brightness;
            int g = pixelColor.G + brightness;
            int b = pixelColor.B + brightness;

            // Ограничиваем значения компонентов (0 - 255)
            r = Math::Max(0, Math::Min(255, r));
            g = Math::Max(0, Math::Min(255, g));
            b = Math::Max(0, Math::Min(255, b));

            // Устанавливаем новый цвет пикселя
            image->SetPixel(x, y, Color::FromArgb(r, g, b));
        }
    }
}

void PhotoeditLR5::MyForm::AdjustContrast(Rectangle rect, float contrastFactor)
{
    double totalBrightness = 0;
    int totalPixels = rect.Width * rect.Height;

    // Проходим по всем пикселям изображения для вычисления среднего значения каналов
    for (int x = rect.Left; x < rect.Right; x++) {
        for (int y = rect.Top; y < rect.Bottom; y++) {
            Color pixelColor = image->GetPixel(x, y);
            double Y = 0.299 * pixelColor.R + 0.587 * pixelColor.G + 0.114 * pixelColor.B;
            totalBrightness += Y;
        }
    }
     
    // Вычисляем среднее значение для каждого канала
    double avgBrightness = totalBrightness / totalPixels;

    for (int x = rect.Left; x < rect.Right; x++)
    {
        for (int y = rect.Top; y < rect.Bottom; y++) {
            // Проверяем, не выходит ли координата за пределы изображения
            if (x < 0 || x >= image->Width || y < 0 || y >= image->Height)
                continue;

            // Получаем цвет пикселя на изображении
            Color pixelColor = image->GetPixel(x, y);

            // Применяем формулу для изменения контрастности Y= K * (Yold - Yav) + Yav
            int r = (int)((pixelColor.R - avgBrightness) * contrastFactor + avgBrightness);
            int g = (int)((pixelColor.G - avgBrightness) * contrastFactor + avgBrightness);
            int b = (int)((pixelColor.B - avgBrightness) * contrastFactor + avgBrightness);

            // Ограничиваем значения компонентов RGB (0 - 255)
            r = Math::Max(0, Math::Min(255, r));
            g = Math::Max(0, Math::Min(255, g));
            b = Math::Max(0, Math::Min(255, b));

            // Устанавливаем новый цвет пикселя
            image->SetPixel(x, y, Color::FromArgb(r, g, b));
        }
    }
}
