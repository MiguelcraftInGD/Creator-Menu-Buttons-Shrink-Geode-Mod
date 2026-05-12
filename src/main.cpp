#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>
using namespace geode::prelude;
class $modify(MyCreatorLayer, CreatorLayer) {
	bool init() {
		if (!CreatorLayer::init()) return false;
		auto menu = this->getChildByID("creator-buttons-menu");
		for (auto child : CCArrayExt<CCNode*>(menu->getChildren())) {
			auto item = typeinfo_cast<CCMenuItemSpriteExtra*>(child);
			if (!item) continue;
			auto sprite = item->getNormalImage();
			if (sprite) {
				sprite->setScale(0.4f);
			}
			item->setContentSize({41.8f, 41.8f});
		}
		return true;
	}
};
