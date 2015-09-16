Sometimes when I upload arduino code I get Exception (0) followed by a stack dump. Sometimes it resets, sometimes it repeatedly says Fetal Exception (0), usually though, the esp8266 just powers down or enters a low power state.

I'll use this code as an example https://github.com/esp8266/Arduino/blob/ea302aab05480ad36c076b618abb642b1eb1893b/hardware/esp8266com/esp8266/libraries/ESP8266WiFi/examples/WiFiAccessPoint/WiFiAccessPoint.ino

When I upload it, the serial from my device simply outputs a bunch of garbage followed by

```
ets Jan  8 2013,rst cause:2, boot mode:(1,7)
```

When I upload it exactly as is a second time I get this

![stacktrace](http://i.imgur.com/46ECGy7.png)

And when I modify the code slightly by adding additional delays and print statements, the device simply powers off without outputting any serial output.
