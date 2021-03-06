#pragma once

#include <fmt/format.h>
#include "ALabel.hpp"
#include "bar.hpp"
#include "client.hpp"
#include "modules/sway/ipc/client.hpp"
#include "util/sleeper_thread.hpp"

namespace waybar::modules::sway {

class Mode : public ALabel {
 public:
  Mode(const std::string&, const waybar::Bar&, const Json::Value&);
  ~Mode() = default;
  auto update() -> void;

 private:
  void onEvent(const struct Ipc::ipc_response);
  void worker();

  const Bar&                  bar_;
  waybar::util::SleeperThread thread_;
  Ipc                         ipc_;
  std::string                 mode_;
};

}  // namespace waybar::modules::sway