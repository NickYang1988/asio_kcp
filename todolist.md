# TODO List

- [x] 考虑单元测试. gtest gmock
- [x] 制作client_lib
- [ ] client发connect包 (_暂时没明白原作者的意思_)
- [ ] 包输出日志, 考虑日志构架 - spdlog
- [ ] 包输出引入packet_id_for_log
- [ ] client_lib connect函数引入参数 connect_timeout
- [ ] handle the re recving the connect packet.  e.g. resend by client because of lag.
- [ ] 添加用户身份验证, 防止恶意攻击.
- [ ] 添加包内容验证，防止传输出错, 恶意修改, 恶意攻击.
