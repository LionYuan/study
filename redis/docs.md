####redis数据结构类型及实现

####redis单机实现架构

####redis数据同步方式

####redis集群方案
    <br/>[redis集群方案介绍](https://juejin.im/post/5a707f4d5188255a8817f5b1)
- 官方cluster方案

- twemproxy代理方案

- 哨兵模式

- codis

- 客户端分片
<br/>分区的逻辑在客户端实现，由客户端自己选择请求到哪个节点。方案可参考一致性哈希，这种方案通常适用于用户对客户端的行为有完全控制能力的场景。
    - 一致性hash方案


####问题列表
* codis 和 twemproxy的区别
* [LVS,Keepalived,HAproxy区别与联系](https://www.cnblogs.com/xuelangos/p/6816009.html)

####高性能高可用相关
* LVS
* [keepalived](https://www.cnblogs.com/kevingrace/p/6248941.html)
* haproxy
* heartbeat
