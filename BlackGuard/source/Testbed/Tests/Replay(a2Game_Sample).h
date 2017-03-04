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
		ANNWeights* weights = new ANNWeights({36,20, 2}, {false, true, false}, {false, true, true}, true);
		//double t[18] = {0.6787432189759287,0.32402882379684017,0.38138679845646567,0.6596121828150271,-0.39075348218771255,0.7751558175474502,0.7128180816515084,0.8331869034928222,0.8639889882667555,0.6049473877868817,0.4230168161558823,0.7467644907877397,0.98997247229515,0.5157477081458126,0.28726306142514413,0.7764763982283777,0.08360215455382215,-0.4918562084407389};

		//weights->Set(t);
		m_scenemgr = new FScene(&m_scenemgr_conf, weights);

		m_monitor = new FMonitor;
		static_cast<FMonitor*>(m_monitor)->f(m_scenemgr);
	}

	void Step(Settings* settings) {
		Test::Step(settings);
		static_cast<FMonitor*>(m_monitor)->Step();
		std::cout<<m_stepCount<<" : "<<static_cast<FMonitor*>(m_monitor)->fitness<<std::endl;
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
