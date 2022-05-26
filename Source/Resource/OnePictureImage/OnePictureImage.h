#pragma once

namespace res {
	enum END_CARD_TYPE {
		STORY,
		END_CARD_MAX
	};
	class OnePictureImage {
	public:
		int end_card[END_CARD_MAX];
		static void load();
		static OnePictureImage one_picture;
	};
}