# Cursor 中配置 C++ 开发环境（Windows）

## 1. 安装 C++ 编译器

### 1.1 安装 MSYS2

1. 前往 [MSYS2 官网](https://www.msys2.org/) 下载安装程序
2. 运行安装程序，默认安装路径为 `C:\msys64`
3. 安装完成后，打开 **MSYS2 UCRT64** 终端

### 1.2 安装 GCC 工具链

在 MSYS2 终端中运行：

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc
```

这会安装 `g++`、`gcc`、`gdb` 等工具。

### 1.3 添加环境变量

将编译器路径添加到系统 `PATH`，有两种方式：

**方式一：图形界面**

1. `Win + S` 搜索 **"环境变量"**，点击 **"编辑系统环境变量"**
2. 点击 **"环境变量"** 按钮
3. 在 **系统变量** 中找到 `Path`，双击打开
4. 点击 **"新建"**，输入 `C:\msys64\ucrt64\bin`
5. 依次点击 **确定** 关闭所有窗口

**方式二：PowerShell（管理员）**

```powershell
[Environment]::SetEnvironmentVariable("Path", [Environment]::GetEnvironmentVariable("Path", "Machine") + ";C:\msys64\ucrt64\bin", "Machine")
```

### 1.4 验证安装

**重启 Cursor**，打开终端运行：

```powershell
g++ --version
gdb --version
```

输出版本信息即表示安装成功。

---

## 2. 安装 Cursor 扩展

打开 Cursor 扩展市场（`Ctrl + Shift + X`），安装以下扩展：

| 扩展名称 | 作者 | 说明 |
| --- | --- | --- |
| **C/C++** | Microsoft | 核心扩展，提供 IntelliSense、调试、代码浏览 |
| **C/C++ Extension Pack** | Microsoft | 可选，包含额外辅助工具 |

---

## 3. 配置编译任务

在项目根目录创建 `.vscode/tasks.json`：

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build",
            "type": "shell",
            "command": "g++",
            "args": [
                "-g",
                "-std=c++17",
                "${file}",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}.exe"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": ["$gcc"]
        }
    ]
}
```

配置完成后，打开任意 `.cpp` 文件，按 `Ctrl + Shift + B` 即可编译。

---

## 4. 配置调试

在项目根目录创建 `.vscode/launch.json`：

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "C++ Debug",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/${fileBasenameNoExtension}.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "build"
        }
    ]
}
```

配置完成后，按 `F5` 即可编译并启动调试。

---

## 5. 配置 IntelliSense

如果代码智能提示不正常（如头文件找不到），创建 `.vscode/c_cpp_properties.json`：

```json
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": [],
            "compilerPath": "C:/msys64/ucrt64/bin/g++.exe",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "windows-gcc-x64"
        }
    ],
    "version": 4
}
```

> **注意**：`compilerPath` 需要与你实际的 `g++` 安装路径一致。

---

## 6. 常用快捷键

| 快捷键 | 功能 |
| --- | --- |
| `Ctrl + Shift + B` | 编译当前文件 |
| `F5` | 编译并调试 |
| `F9` | 切换断点 |
| `F10` | 单步跳过 |
| `F11` | 单步进入 |
| `Shift + F11` | 单步跳出 |
| `Ctrl + Shift + \`` | 打开终端 |

---

## 7. 日常使用流程

```
打开 .cpp 文件 → Ctrl+Shift+B 编译 → F5 调试（或终端运行 .exe）
```

如果只想在终端中手动编译运行：

```powershell
g++ -std=c++17 -o solution.exe HashTable.cpp
./solution.exe
```
