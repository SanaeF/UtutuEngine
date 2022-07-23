#include "FrameMask.h"
#include "../../Source/library/Graphics/Mask/Mask.h"
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/Resource/GUI/GameUIImage/GameUIImage.h"
namespace app {
	void FrameMask::start(int count) {
		m_Fade_in.start(count, AreaProp::frame_hight);
	}
	void FrameMask::draw() {
		lib::Mask::createScreen();
		auto resized_frame = AreaProp::resizeFrame(AreaProp::frame_width, AreaProp::frame_hight);
		if (m_Fade_in.isFlag()) {
			resized_frame = AreaProp::resizeFrame(AreaProp::frame_width, m_Fade_in.getSize());
		}
		lib::Mask::drawFill(
			resized_frame.min_x,
			resized_frame.min_y,
			resized_frame.max_x,
			resized_frame.max_y,
			res::GameUIImage::game_ui.score_board[res::BOARD_TYPE::FRAME_MASK]
		);
		m_Fade_in.update();
	}
	void FrameMask::clear() {
		lib::Mask::deleteScreen();
	}
}