#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>

using namespace geode::prelude;

class $modify(MyCreatorLayer, CreatorLayer) {
    bool init() {
        if (!CreatorLayer::init()) return false;

        auto menu = this->getChildByID("creator-buttons-menu");
        if (!menu) return true;

        for (auto child : CCArrayExt<CCNode*>(menu->getChildren())) {
            auto item = typeinfo_cast<CCMenuItemSpriteExtra*>(child);
            if (!item) continue;

            // Resize the internal sprite
            auto sprite = item->getNormalImage();
            if (sprite) {
                sprite->setScale(0.4f);
            }

            // Force content size
            item->setContentSize({41.8f, 41.8f});

            // Optional: fix anchor & positioning issues
            item->setAnchorPoint({0.5f, 0.5f});
            if (sprite) {
                sprite->setPosition(item->getContentSize() / 2);
            }
        }

        return true;
    }
};