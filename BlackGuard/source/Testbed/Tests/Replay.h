/*
 * Replay.h
 *
 *  Created on: Jan 14, 2015
 *      Author: wei
 */

#ifndef REPLAY_H_
#define REPLAY_H_

#include <iostream>
#include <fstream>

/// Simulation entrance.
class Replay: public Test {
public:
	Replay() {
		ANNWeights* w= new ANNWeights({19, 20, 2}, {false, true, false}, {false, true, true}, true);
		double w_c[] = {};
		w->Randomize();

		S_Field::Configuration sc;
		sc.TimeStep = 0.02;
		sc.World = m_world;
		sc.Robot=50;
		m_scenemgr = new  S_Field(&sc, w);
	}

	void Step(Settings* settings) {
		std::cout<<m_stepCount<<":   ";
		Test::Step(settings);

//		for(int i = 150; i < 152; i++) {
//			std::cout<<static_cast<S_Field*>(m_scenemgr)->m_robot[9]->GetDataPool().Get<float>(i)<<", ";
//		}

		Draw_W();
		std::cout<<std::endl;
	}

	/// Draw Nests.
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

	void DrawCircleNest(const b2Vec2& center, float32 radius, const b2Color& color) {
		m_debugDraw.DrawCircle(center, radius, color);
	}

	/// Implementation function.
	static Test* Create() {
		return new Replay;
	}

	//////// Draw
	void Draw_W() {
			b2Vec2 w_v[10];

			w_v[7] = b2Vec2(24.85282f, 60.0f);
			w_v[6] = b2Vec2(-24.85282f, 60.0f);
			w_v[5] = b2Vec2(-60.0f, 24.85282f);
			w_v[4] = b2Vec2(-60.0f, -24.85282f);
			w_v[3] = b2Vec2(-24.85282f, -60.0f);
			w_v[2] = b2Vec2(24.85282f, -60.0f);
			w_v[1] = b2Vec2(60.0f, -24.85282f);
			w_v[0] = b2Vec2(60.0f, 24.85282f);
			DrawSolidPolygon(w_v, 8, b2Color(0.8, 0.8, 0.8));

			// walls
			DrawSegment(b2Vec2(24.85282f, 60.0f), b2Vec2(-24.85282f, 60.0f), b2Color(0.0f, 0.0f, 0.0f));
			DrawSegment(b2Vec2(-24.85282f, 60.0f), b2Vec2(-60.0f, 24.85282f), b2Color(0.0f, 0.0f, 0.0f));
			DrawSegment(b2Vec2(-60.0f, 24.85282f), b2Vec2(-60.0f, -24.85282f), b2Color(0.0f, 0.0f, 0.0f));
			DrawSegment(b2Vec2(-60.0f, -24.85282f), b2Vec2(-24.85282f, -60.0f), b2Color(0.0f, 0.0f, 0.0f));
			DrawSegment(b2Vec2(-24.85282f, -60.0f), b2Vec2(24.85282f, -60.0f), b2Color(0.0f, 0.0f, 0.0f));
			DrawSegment(b2Vec2(24.85282f, -60.0f), b2Vec2(60.0f, -24.85282f), b2Color(0.0f, 0.0f, 0.0f));
			DrawSegment(b2Vec2(60.0f, -24.85282f), b2Vec2(60.0f, 24.85282f), b2Color(0.0f, 0.0f, 0.0f));
			DrawSegment(b2Vec2(60.0f, 24.85282f), b2Vec2(24.85282f, 60.0f), b2Color(0.0f, 0.0f, 0.0f));

			// nest
			DrawSolidCircle(b2Vec2(0.0f, 0.0f), 15.0f, b2Color(0.65f, 0.65f, 0.65f));

			// robots
			for(auto robot : m_scenemgr->GetNodesByTag(MAKE_TAG('r', 'o', 'b', 'o'))) {
				b2Body* bd1 = static_cast<A_Robot*>(robot)->m_motor[0]->GetBody();
				w_v[0] = bd1->GetWorldPoint(b2Vec2(-0.25, -0.1));
				w_v[1] = bd1->GetWorldPoint(b2Vec2(0.25, -0.1));
				w_v[2] = bd1->GetWorldPoint(b2Vec2(0.25, 0.1));
				w_v[3] = bd1->GetWorldPoint(b2Vec2(-0.25, 0.1));
				DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));
				b2Body* bd2 = static_cast<A_Robot*>(robot)->m_motor[1]->GetBody();
				w_v[0] = bd2->GetWorldPoint(b2Vec2(-0.25, -0.1));
				w_v[1] = bd2->GetWorldPoint(b2Vec2(0.25, -0.1));
				w_v[2] = bd2->GetWorldPoint(b2Vec2(0.25, 0.1));
				w_v[3] = bd2->GetWorldPoint(b2Vec2(-0.25, 0.1));
				DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));
				b2Color col(0.0f, 0.0f, 0.9f);

	 			DrawSolidCircle(static_cast<A_Robot*>(robot)->GetMainComponent()->GetPosition(), 0.5f, col);

				if(robot->GetId()==9) {
					m_debugDraw.DrawCircle(static_cast<A_Robot*>(robot)->GetMainComponent()->GetPosition(), 15.0f, b2Color(0.4,0.9,0.8));
				}
			}

			// resource
			if(m_scenemgr->CountNodesByTag(MAKE_TAG('r', 'e', 's', 'o')) > 0) {
				for(auto resource : m_scenemgr->GetNodesByTag(MAKE_TAG('r', 'e', 's', 'o'))) {
					b2Color col;
					if(resource->GetFlag()==0) {
						col.Set(0.25f, 0.55f, 0.0f);
					} else {
						col.Set(0.9f, 0.0f, 0.0f);
					}
					DrawSolidCircle(static_cast<Block*>(resource)->GetPosition(), static_cast<Block*>(resource)->GetBody()->GetFixtureList()->GetShape()->m_radius, col);
				}
			}
		}
};

#endif /* REPLAY_H_ */
