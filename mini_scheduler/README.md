# Mini Task Scheduler (輕量級任務排程器)

## 專案簡介
這是一個基於 C 語言實作的「靜態記憶體池」任務排程器。  
目的是在無作業系統（Bare-metal）環境下，模擬 RTOS 的任務控制、掛起與恢復機制。

## 核心功能
- **靜態記憶體池**：使用block_alloc/block_free管理固定大小區塊（無碎片問題）。
- **任務控制塊 (TCB)**：包含任務函式指標、執行週期、狀態（就緒/暫停）。
- **非搶佔式排程**：輪詢任務陣列，依 `state` 決定是否執行。
- **獨立週期控制**：每個任務可設定不同的period，透過last_run計算下次執行時間。

## 專案檔案結構
mini_scheduler/
├── main.c # 主程式（任務定義與排程迴圈）
├── pool.c # 記憶體池實作（block_alloc / block_free）
├── main_term_tast.c # 壓力測試 1 原始碼（動態掛起任務）
├── test_pool_limit.c # 壓力測試 2 原始碼（記憶體池邊界測試）
├── Makefile # 編譯設定
└── README.md # 本文件


### 測試 1：動態掛起任務 (State Control)
- 測試目標：驗證 `task_blink` 在執行 3 次後，能否將 `task_read_sensor` 的 `state` 設為 0。
- 執行結果（節錄）：
LED is blinking...
Sensor value:42
LED is blinking...
***[EVENT]Task 2 suspended by Task 1 at count3 ***
（後續只剩 LED is blinking...）
「觀察結果：第 3 次 blink 後，Sensor 任務確實被掛起，證明 state 控制機制有效。」



### 測試 2：記憶體池邊界測試 (Pool Exhaustion)
- 測試目標：連續配置 33 次，確認第 33 次回傳 `NULL`。
- 執行結果（節錄）：
Alloc30:0x7fd08d38b400
Alloc31:0x7fd08d38b420
Alloc32:(nil)
POOL EXHAUSTED!
