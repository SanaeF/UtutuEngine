#include "OnePictureImage.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
namespace res {
	OnePictureImage OnePictureImage::one_picture;
	void OnePictureImage::load() {
		one_picture.end_card[END_CARD_TYPE::STORY] = lib::Graphics2D::load("./dat/image/OnePicture/EndCard/Story.png");
	}
}