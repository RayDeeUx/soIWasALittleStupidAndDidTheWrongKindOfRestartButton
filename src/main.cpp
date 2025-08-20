#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(MyPlayLayer, PlayLayer) {
	void setupHasCompleted() {
		PlayLayer::setupHasCompleted();
		if (!m_uiLayer || !m_uiLayer->m_pauseBtn || !m_uiLayer->m_pauseBtn->getParent()) return log::info("could not find UILayer or its pause button :(");
		CCSprite* restartSprite = CCSprite::create("consume.png"_spr);
		if (!restartSprite || restartSprite->getUserObject("geode.texture-loader/fallback")) return log::info("could not create sprite restart.png_spr");
		CCMenuItemSpriteExtra* restartButton = CCMenuItemSpriteExtra::create(restartSprite, this, menu_selector(MyPlayLayer::onEchoRestart));
		restartButton->setID("restart-button"_spr);
		restartButton->setTag(8202025);
		m_uiLayer->m_pauseBtn->getParent()->addChild(restartButton);
		restartButton->setPosition(m_uiLayer->m_pauseBtn->getPosition());
		restartButton->setPositionY(restartButton->getPositionY() - 30.f);
		restartButton->setOpacity(128);
	}
	void onEchoRestart(CCObject* sender) {
		PlayLayer::resetLevel();
	}
};