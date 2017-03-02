/*
 * Replay(a2Game_Sample).h
 *
 *  Created on: Jan 14, 2015
 *      Author: wei
 */

#ifndef REPLAY_A2GAME_SAMPLE__H_
#define REPLAY_A2GAME_SAMPLE__H_

#include <iostream>
#include <fstream>

class Replay_a2Game_Sample: public Test {
public:

	Replay_a2Game_Sample() {


		m_scenemgr = new FScene(&m_scenemgr_conf);
		//m_evaluationManager = new a2EvaluationManager_Sample;
		m_world = m_scenemgr->GetWorld();
		m_world->SetDestructionListener(&m_destructionListener);
		m_world->SetContactListener(this);
		m_world->SetDebugDraw(&m_debugDraw);
		b2BodyDef bodyDef;
		m_groundBody = m_world->CreateBody(&bodyDef);


	}

	void Step(Settings* settings) {

		Test::Step(settings);

		//DrawNest(5.0f);


	}

	void DrawNest(float a) {
		m_debugDraw.DrawSegment(b2Vec2(-a, -a), b2Vec2(-a, a),
				b2Color(0.8f, 0.8f, 0.8f));
		m_debugDraw.DrawSegment(b2Vec2(-a, a), b2Vec2(a, a),
				b2Color(0.8f, 0.8f, 0.8f));
		m_debugDraw.DrawSegment(b2Vec2(a, a), b2Vec2(a, -a),
				b2Color(0.8f, 0.8f, 0.8f));
		m_debugDraw.DrawSegment(b2Vec2(a, -a), b2Vec2(-a, -a),
				b2Color(0.8f, 0.8f, 0.8f));
	}

	static Test* Create() {
		return new Replay_a2Game_Sample;
	}
};

#endif /* REPLAY_A2GAME_SAMPLE__H_ */
