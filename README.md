# Optional Qounters++

Allows integration with Qounters++ without requiring the mod to be present. [API Docs](https://github.com/Metalit/Qounters?tab=readme-ov-file#custom-qounter-mods).

`InSettings()`, `IsEnabled`, and `IsEnabledForSelection` (and `IsInstalled` of course) are still valid to use even if `IsInstalled()` is false. All other functions will throw exceptions if called without Qounters++, and variables will be uninitialized.
