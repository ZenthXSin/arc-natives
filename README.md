# Arc Natives

Arc 框架的预编译 native 库，打包为独立 artifact，供 `mindustry-mod-validator-full` 使用。

## 包含内容

### 核心 natives（从 Arc d72b19223f 源码树提取）

| 平台 | 文件名 | 作用 |
|------|--------|------|
| Linux x64 | `libarc64.so` | 核心 JNI（Buffers/Soloud 音频） |
| Windows x64 | `arc64.dll` | 同上 |
| macOS x64 | `libarc64.dylib` | 同上 |
| macOS ARM64 | `libarcarm64.dylib` | 同上 |

### 扩展 natives（从 Mindustry v159.7 release jar 提取）

| 文件名 | 作用 |
|--------|------|
| `libarc-freetype64.so/dll/dylib` | FreeType 字体渲染 |
| `libarc-filedialogs64.so/dll/dylib` | 原生文件对话框 |

### 补丁 natives（手写 JNI 实现）

| 文件名 | 作用 |
|--------|------|
| `libnativeutils64.so` | `NativeUtils.setEnv/unsetEnv/getEnv` |

> 补丁原因：JitPack 构建的 `arc-core:7b92242511` 新增了 `NativeUtils` 类，但源码树预编译 natives 不含对应方法。手写 POSIX 实现补全。

### 资源文件

| 路径 | 作用 |
|------|------|
| `cursors/cursor.png` | 系统光标（占位图） |
| `cursors/hand.png` | 手型光标 |
| `cursors/ibeam.png` | 文本光标 |

## 用法

```groovy
dependencies {
    implementation 'com.github.ZenthXSin:arc-natives:1.0.0'
}
```

所有文件在 jar 根路径，运行时自动加载当前平台对应的文件。

## 跨平台

运行时 `SharedLibraryLoader.mapLibraryName("arc")` 自动选择：
- Linux x64 → `libarc64.so`
- Windows x64 → `arc64.dll`
- macOS x64 → `libarc64.dylib`
- macOS ARM → `libarcarm64.dylib`

## 构建

```bash
./gradlew jar
```

## License

与 Arc/Mindustry 相同（GPLv3）
