# Client lib usage

> You can use asio_kcp client_lib in a event-driven framework (recommend) OR using in a simple environment do not have a event-driven framework.

## Using asio_kcp_client in a event-driven framework

You should hook a timer for calling the `kcp_client.update()`
all code running in your coding thread. This is no other thread.

You can set event_callback_func or not.

### Using event_callback_func

in class header define a member client_;

```cpp
kcp_client client_;
```

in An event handle:

```cpp
client_.set_event_callback();
// hook 5milliseconds_timer_handle in your event-driven framework
client_.connect_async();
```

in 5 milliseconds_timer_handle

```cpp
client_.update();
```

`client_.update` will call event_callback_func back (in same thread) when connect succeed or failed.

aftering the success of connection. You can call c.send_msg in your code,
`client_.update()` in 5milliseconds_timer_handle will call event_callback_func back (in same thread) when recved some msg or some error.

### Not using event_callback_func

in class header define a member client_;

```cpp
kcp_client client_;
```

in An event handle:
hook 5milliseconds_timer_handle in your event-driven framework

```cpp
client_.connect_async()
```

in 5 milliseconds_timer_handle

```cpp
client_.update();
events = client_.grab_events();
events.for_each(/*handle event*/);
```

aftering the success of connection. You can call c.send_msg in your code
`client_.update()` in 5milliseconds_timer_handle will call event_callback_func back (in same thread) when recved some msg or some error.

## Using asio_kcp_client without a event-driven framework

please using kcp_client_wrap.  
kcp_client_wrap is a facade of kcp_client.  
This facade is easy to use.  
You do not need use it in an event-driven framework such as boost.asio, libevent, cocos2d, or implement by our own.  
Please using kcp_client directly if you coding in an event-driven framework. That's more effective.  
kcp_client_wrap will create a work thread that control the udp packet sending and recving.  

## sync using

```cpp
kcp_client_wrap c;
c.connect   // this will block until connect succeed or failed.
while (true)
{
    // do your things
    // if (some msg need send to server)
    //     c.send_msg();
    events = c.grab_events();
    handle_events(events);  // your func
    millisecond_sleep(1); // if you want.
}
```

### You can async the connection stage or event handle stage.

async the connect stage

```cpp
kcp_client_wrap c;
c.connect_async();
while (c.connect_result() == 1)
    millisecond_sleep(1);
```

async connect with callback_func

```cpp
kcp_client_wrap c;
c.set_event_callback_func();
c.connect_async();

// do something

// kcp_client_wrap will call event_callback_func in another thread.
// note: you should making event_callback_func multithread safe.

```

async event handle

```cpp
kcp_client_wrap c;
c.set_event_callback
c.connect();
// or using  async mode
// c.connect_async();
while (true)
{
    // do your things
    //if some msg need send to server
    //    c.send_msg
    // millisecond_sleep(1) if you want.
}

// do something

// kcp_client_wrap will call event_call_back_func in another thread.
// note: you should making event_call_back_func multithread safe.
```
