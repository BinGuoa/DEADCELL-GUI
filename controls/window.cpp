#include "window.h"

#include <algorithm>

#include "../wrapped/drawing.h"

namespace deadcell::gui {
    window::window() {

    }

    void window::event(const base_event &e) {
        const auto &io = ImGui::GetIO();

        if (io.MousePos.x != last_mouse_pos_.x || io.MousePos.y != last_mouse_pos_.y) {
            if (dragging_) {
                min_ = min_ + (io.MousePos - drag_start_);
            }
        }

        if (e.type() == window_event::left_mouse_down) {
            dragging_ = true;
            drag_start_ = { io.MousePos.x, io.MousePos.y };
        }

        if (e.type() == window_event::left_mouse_up) {
            if (dragging_) {
                dragging_ = false;
            }
        }

        last_mouse_pos_ = io.MousePos;
    }

    void window::render() {
        drawing::rect_filled(min_, max_, IM_COL32(255, 255, 255, 255), 0.0f, 0);
        drawing::rect_filled(min_, max_, IM_COL32(0, 255, 255, 255), 23.0f, 0);
    }
}
