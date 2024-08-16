# windows_sleep_techniques
A collections of methods to sleep on Windows using common and less-so-common techniques

## Techniques

### Standard Sleep()
Uses the most obvious and common Sleep() call from Windows.h.

### CreateTimerQueue()
Lesser-known technique but still very common. Used in [Ekko](https://github.com/Cracked5pider/Ekko)

### Multimedia Timers (timeSetEvent)
Works well

### Busy Sleep
Very accurate and high-resolution technique. Also doesn't call any suspicious APIs. Only problem is that it will use 100% cpu while it's sleeping.

### Ping Sleep
Unconvenient technique where you use ping commands to sleep for N seconds. Common in batch scripts.