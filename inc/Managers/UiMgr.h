/*
 * UiMgr.h
 *
 *  Created on: Apr 12, 2017
 *      Author: chad
 */

#ifndef INC_UIMGR_H_
#define INC_UIMGR_H_

#include <OgreWindowEventUtilities.h>
#include <OgreTextAreaOverlayElement.h>
#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>
#include <Managers/Mgr.h>
#include <string>

#include <SdkTrays.h>

class UiMgr : public Mgr, public Ogre::FrameListener, public OIS::KeyListener, public OIS::MouseListener, public Ogre::WindowEventListener, public OgreBites::SdkTrayListener
{
private:


protected:
	virtual void windowResized(Ogre::RenderWindow *rw);
	virtual void windowClosed(Ogre::RenderWindow *rw);

    virtual bool keyPressed(const OIS::KeyEvent &arg);
    virtual bool keyReleased(const OIS::KeyEvent &arg);
    virtual bool mouseMoved(const OIS::MouseEvent &arg);
    virtual bool mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
    virtual bool mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);

    void buttonHit(OgreBites::Button *b);
    void itemSelected(OgreBites::SelectMenu *m);

public:

	UiMgr(Engine *engine);
	~UiMgr();
	virtual void Init();
	virtual void Tick(float dt);
	virtual void LoadLevel(std::string levelLocation);
	virtual void stop();

	OgreBites::InputContext m_InputContext;
	OgreBites::SdkTrayManager* m_TrayMgr;
	Ogre::OverlaySystem* m_OverlaySystem;
	OgreBites::Label *m_Label;
	OgreBites::Label *m_InfoEntityType;
	OgreBites::Label *m_InfoEntityName;
	OgreBites::Label *m_InfoEntitySpeed;
	Ogre::TextAreaOverlayElement *m_TextArea;
	Ogre::OverlayContainer *m_Panel;
	Ogre::Overlay* m_Overlay;
	
	unsigned int m_PlayerCount = 5;
};

#endif /* INC_UIMGR_H_ */
