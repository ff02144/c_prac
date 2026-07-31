# CHIP-8 模擬器

一個用 C 語言實作的 CHIP-8 模擬器，支援遊戲 ROM 載入與 SDL2 圖形顯示。

---

## 功能特色

- 實作全部 35 條 CHIP-8 指令
- 60Hz 時序控制（每幀執行 15 條指令）
- SDL2 繪圖（960x480，15 倍放大）
- 標準 CHIP-8 鍵盤對應（1 2 3 4 / Q W E R / A S D F / Z X C V）
- 支援載入任何 .ch8 格式的 ROM

---

## 編譯與執行

./chip8 <rom_file.ch8>
(ex: ./chip8 PONG)

### 依賴套件
- gcc（編譯器）
- SDL2 開發函式庫

### 檔案結構
- `main.c` - 主迴圈、指令集、CPU 邏輯
- `display.c` / `display.h` - SDL2 視窗、繪圖、鍵盤事件
- `font.c` / `font.h` - CHIP-8 字型資料
- `rom.c` / `rom.h` - ROM 檔案載入
- `Makefile` - 編譯設定

### 編譯
```bash
-make
