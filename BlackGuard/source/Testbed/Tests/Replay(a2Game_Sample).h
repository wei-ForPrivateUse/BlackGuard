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
		ANNWeights* weights = new ANNWeights({28, 20, 2}, {false, true, false}, {false, true, true}, true);

		double w[1022];
		for(int i = 0; i < 1022; i++) {
			w[i] = assa2d::RandomFloat();
		}

		weights->Set(w);
		m_scenemgr = new FScene(&m_scenemgr_conf, weights);

		m_monitor = new FMonitor;
		static_cast<FMonitor*>(m_monitor)->f(m_scenemgr);
	}

	void Step(Settings* settings) {
		Test::Step(settings);
		//static_cast<FMonitor*>(m_monitor)->Step();
		DrawNest(10.0f);
	//	std::cout<<m_stepCount<<" : "<<static_cast<FMonitor*>(m_monitor)->fitness<<std::endl;
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
