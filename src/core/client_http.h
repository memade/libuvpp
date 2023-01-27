#if !defined(__2834C698_237C_4998_A116_2A3B5A5236AD__)
#define __2834C698_237C_4998_A116_2A3B5A5236AD__

namespace local {

 class ClientHttp final : public IClientHttp {
  std::shared_ptr<std::mutex> m_Mutex = std::make_shared<std::mutex>();
 public:
  ClientHttp();
  virtual ~ClientHttp();
 public:
  void Release() const override final;
 };

}///namespace local

/// /*_ Memade®（新生™） _**/
/// /*_ Thu, 26 Jan 2023 03:20:46 GMT _**/
/// /*_____ https://www.skstu.com/ _____ **/
#endif///__2834C698_237C_4998_A116_2A3B5A5236AD__