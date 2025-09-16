## Cấu trúc dự án
```txt
robot-draw/
├── src/
│   ├── main.cpp               # Điểm vào chương trình, xử lý arguments và điều phối luồng chính
│   ├── Grid.h/.cpp            # Quản lý lưới vẽ và trạng thái các ô
│   ├── Robot.h/.cpp           # Điều khiển robot và thuật toán vẽ đường
│   ├── ICommand.h             # Interface abstract cho tất cả các command
│   ├── Command.h/.cpp         # Implementations cụ thể cho từng loại command
│   └── CommandFactory.h/.cpp  # Factory pattern để tạo commands từ file input
├── tests/                     # Unit tests (GoogleTest) cho các components
└── CMakeLists.txt             # Cấu hình build system
```
## Yêu cầu hệ thống

+ CMake version 3.10 hoặc cao hơn

+ C++ compiler hỗ trợ C++20 (GCC, Clang, hoặc MSVC)

+ GoogleTest (đã bao gồm trong thư mục external)

## Cách sử dụng cho Powershell
Tạo thư mục và biên dịch
```bash
# Tạo thư mục build
mkdir build
cd build

# Config và build project
cmake ..
cmake --build .
```

Chạy chương trình
```bash
# Có sẵn ở thư mục cha, có thể thực hiện lệnh ./robot ../commands.txt
./robot <command_file.txt>
```

Chạy tests
```bash
./tests
```

Xóa thư mục
```bash
# Xóa thư mục build để build lại từ đầu
Remove-Item -Recurse -Force build
```

## Nâng cấp hiệu năng bằng cách áp dụng Multithreading (Có thể tham khảo)
Hiện tại, nếu tính toán và vẽ theo thứ tự từng điểm (x, y) tuần tự, CPU chỉ xử lý một công việc tại một thời điểm, dẫn đến:

+ Thời gian chờ dài nếu số điểm nhiều.

+ CPU không tận dụng hết các lõi.

Nếu tách mỗi điểm hoặc nhóm điểm thành một thread riêng, mỗi thread có thể tính toán và vẽ độc lập. Ý tưởng đơn giản, mỗi request command sẽ đều phụ thuộc điểm (x, y) trước đó thì mình có thể lưu điểm trước đó để thực hiện độc lập từng thread riêng biệt lại với nhau.