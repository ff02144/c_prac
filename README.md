# C 語言專案集

這個 Repository 是我練習 C 語言與系統程式設計的集中地，包含獨立專案與日常語法練習。

---

## 📁 專案列表

### 1. 🟢 CHIP-8 模擬器（`/chip8`）

一個用 C 語言實作的 CHIP-8 模擬器，支援遊戲 ROM 載入與 SDL2 圖形顯示。

**功能特色**
- 實作全部 35 條 CHIP-8 指令
- 60Hz 時序控制（每幀執行 15 條指令）
- SDL2 繪圖（960x480，15 倍放大）
- 標準 CHIP-8 鍵盤對應（1 2 3 4 / Q W E R / A S D F / Z X C V）
- 支援載入任何 .ch8 格式的 ROM

**編譯與執行**
```bash
make
./chip8 <rom_file.ch8>   # 例如：./chip8 PONG
```

**依賴套件**：`gcc`、`SDL2` 開發函式庫

**詳細檔案結構**（僅列主要檔案）：
- `main.c` - 主迴圈、指令集、CPU 邏輯
- `display.c/h` - SDL2 視窗、繪圖、鍵盤事件
- `font.c/h` - CHIP-8 字型資料
- `rom.c/h` - ROM 檔案載入
- `Makefile` - 編譯設定

> 完整實作細節請參閱 `/chip8` 目錄下的原始碼。

**DEMO**
[影片](https://youtu.be/sgXWxmbDjMs)

---

### 2. 🔄 迷你排程器（`/mini_scheduler`）

一個基於**靜態記憶體池**與**時間觸發**的協同式任務排程器，專為資源受限的嵌入式環境（如 MCU）設計。

**技術亮點**
- **靜態記憶體管理**：使用 1KB 靜態陣列（`pool`）切分為 32 個固定大小區塊（每塊 32 bytes），透過位元圖（`block_map`）管理分配，杜絕記憶體碎片。
- **時間觸發排程**：利用 `time(NULL)` 檢查任務週期，非阻塞式設計，不浪費 CPU 資源。
- **任務控制塊（TCB）**：支援任務函式、執行週期、上次執行時間與狀態管理。
- **範例任務**：內建 LED 閃爍（`task_blink`）與虛擬感測器讀取（`task_read_sensor`）。


## 📁 檔案結構

| 檔案 | 說明 |
| :--- | :--- |
| `main.c` | 排程器主邏輯、任務定義與初始化 |
| `pool.c` | 靜態記憶體池實作（`block_alloc` / `block_free`） |
| `Makefile` | 編譯設定（產生 `scheduler` 執行檔） |


## 🔧 編譯與執行

```bash
make          # 編譯
./scheduler   # 執行排程器
```
> **注意**：執行後會進入無窮迴圈模擬系統運作，請按 `Ctrl + C` 終止。

## 📖 運作原理

1. **記憶體池**：宣告 `uint8_t pool[1024]`，以 `block_map`（32-bit）記錄 32 個區塊的使用狀態（0=空, 1=佔用）。
2. **任務建立**：透過 `block_alloc()` 取得記憶體，填入任務函式指標與週期（`task1` 週期 1 秒，`task2` 週期 2 秒）。
3. **排程迴圈**：主程式 `while(1)` 不斷掃描任務陣列，當 `當前時間 >= 上次執行時間 + 週期` 時觸發任務執行。


## 🧪 預期輸出範例

```text
Mini Scheduler Started!
LED is blinking...
Sensor value:42
LED is blinking...
LED is blinking...
Sensor value:42
...
```

> 詳細設計與程式碼請參閱 `/mini_scheduler` 目錄。

---

### 3. 📂 練習區（`/practice`）

此目錄收錄了過往的 C 語言語法練習與小型作業（如指標操作、資料結構實作等），屬於學習過程中的紀錄，非完整專案。

---


## 🛠 開發與偵錯環境

- **作業系統**：Ubuntu 22.04 LTS（亦適用於其他 Linux 發行版及 WSL）
- **編譯器**：GCC（需支援 C99 以上標準）
- **建構工具**：GNU Make
- **記憶體檢測**：Valgrind（用於檢查記憶體洩漏與非法存取）
- **程式除錯**：GDB（用於中斷點偵錯、變數追蹤與執行流程分析）
