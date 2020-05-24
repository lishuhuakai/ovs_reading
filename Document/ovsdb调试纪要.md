# ovsdb调试日志
gdb调试时候的参数为:
```shell
 r -v --remote=punix:/usr/local/var/run/openvswitch/db.sock
```

## 如何输出json字符串?
使用函数json_to_string:
```shell
printf "%s", json_to_string(json, JSSF_PRETTY)
```

## 关于struct ovsdb_datum这个结构
在ovsdb-data.h中定义。

ovsdb最为底层的一个数据类型:
```c
union ovsdb_atom {
    int64_t integer;
    double real;
    bool boolean;
    char *string;
    struct uuid uuid;
};
```

json会话在
ovsdb_jsonrpc_session_run这个函数里面执行。

ovsdb_jsonrpc_session_got_request用于处理发送过来的请求