# Arc Natives

Arc 框架的预编译 native 库（`libarc64.so` / `arc64.dll` / `libarc64.dylib` / `libarcarm64.dylib`）。

从 Arc 源码树的 `natives/natives-desktop/libs/` 提取，打包为独立 Maven artifact，供 `mindustry-mod-validator-full` 使用。

## 包含的 natives

| 平台 | 文件名 | 大小 |
|------|--------|------|
| Linux x64 | `libarc64.so` | 887K |
| Windows x64 | `arc64.dll` | 782K |
| macOS x64 | `libarc64.dylib` | 674K |
| macOS ARM64 | `libarcarm64.dylib` | 582K |

## 用法

```groovy
dependencies {
    implementation 'com.github.ZenthXSin:arc-natives:1.0.0'
}
```

所有 natives 在 jar 根路径，`ArcNativesLoader` 自动加载当前平台对应的文件。

## 跨平台

运行时 `SharedLibraryLoader.mapLibraryName("arc")` 自动选择：
- Linux x64 → `libarc64.so`
- Windows x64 → `arc64.dll`
- macOS x64 → `libarc64.dylib`
- macOS ARM → `libarcarm64.dylib`

## 来源

Arc commit `d72b19223f` 的预编译 natives。
