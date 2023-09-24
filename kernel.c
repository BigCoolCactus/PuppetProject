char *vidmem = (char*)0xb8000; // Обозначение видео памяти

void printVMEM(const char* str) {      // Вывод в видео-память текст
    unsigned int i = 0;
    unsigned int j = 0;

    while(str[j] != '\0') {
        vidmem[i] = str[j];
        vidmem[i+1] = 0x07;
        ++j;
        i += 2;
    }
}

void clearConsole() {   // Очистка видео-памяти
    unsigned int i = 0;
    unsigned int j = 0;

    while(j < 80 * 25 * 2) {    // Очитска и подготовка экрана 
        vidmem[j] = ' ';
        vidmem[j+1] = 0x07;
        j += 2;
    }
}

void Kernelload() {     // Запуск после загрузки лоадера (bootloader.asm)
    clearConsole();
    printVMEM("Kernel is loaded!");
}