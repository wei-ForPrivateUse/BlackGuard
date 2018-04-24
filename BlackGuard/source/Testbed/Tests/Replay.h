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
		ANNWeights* arbi = new ANNWeights({8, 20, 3}, {false, true, false}, {false, true, true}, true);
		ANNWeights* w1 = new ANNWeights({14, 20, 2}, {false, true, false}, {false, true, true}, true);
		ANNWeights* w2 = new ANNWeights({19, 20, 2}, {false, true, false}, {false, true, true}, true);
		ANNWeights* w3 = new ANNWeights({14, 20, 2}, {false, true, false}, {false, true, true}, true);

		ANNWeights* wa_a = new ANNWeights({28, 20, 2}, {false, true, false}, {false, true, true}, true);
		ANNWeights* wa_d = new ANNWeights({28, 20, 3}, {false, true, false}, {false, true, true}, true);

		//double arbi_c[] = {};
		//double w1_c[] = {};
		//double w2_c[] = {};
		//double w3_c[] = {};

//		double wa_a_c[] = {};
//		double wa_d_c[] = {};

		arbi->Randomize();
		w1->Randomize();
		w2->Randomize();
		w3->Randomize();

		wa_a->Randomize();
		wa_d->Randomize();

//		arbi->Set(arbi_c);
//		w1->Set(w1_c);
//		w2->Set(w2_c);
//		w3->Set(w3_c);

//		wa_a->Set(wa_a_c);
//		wa_d->Set(wa_d_c);

		J0_S_Field::Configuration conf;
		conf.World = m_world;
		conf.TimeStep = 0.02;
		conf.TrainingMode = 1;
		m_scenemgr = new J0_S_Field(&conf, arbi, w1, w2, w3);
		//m_scenemgr = new J0_S_Field_S(&conf, wa_a, wa_d);
	}

	void Step(Settings* settings) {
		std::cout<<m_stepCount<<":   ";
		Test::Step(settings);

//		for(int i = 30; i < 33; i++) {
//			std::cout<<static_cast<J0_S_Field*>(m_scenemgr)->m_robot[0]->GetDataPool().Get<float>(i)<<", ";
//		}

		Draw_Arbi();
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

	/// Draw colors.
	void Draw_Arbi() {
		b2Vec2 w_v[10];

		// walls
		w_v[3] = b2Vec2(69.284f, 20.0f);
		w_v[2] = b2Vec2(69.284f, 21.0f);
		w_v[1] = b2Vec2(48.698f, 21.0f);
		w_v[0] = b2Vec2(48.284f, 20.0f);
		DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));

		w_v[3] = b2Vec2(48.284f, 20.0f);
		w_v[2] = b2Vec2(48.698f, 21.0f);
		w_v[1] = b2Vec2(20.414f, 49.284f);
		w_v[0] = b2Vec2(20.0f, 48.284f);
		DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));

		w_v[3] = b2Vec2(20.0f, 48.284f);
		w_v[2] = b2Vec2(20.414f, 49.284f);
		w_v[1] = b2Vec2(-20.414f, 49.284f);
		w_v[0] = b2Vec2(-20.0f, 48.284f);
		DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));

		w_v[3] = b2Vec2(-20.0f, 48.284f);
		w_v[2] = b2Vec2(-20.414f, 49.284f);
		w_v[1] = b2Vec2(-48.698f, 21.0f);
		w_v[0] = b2Vec2(-48.284f, 20.0f);
		DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));

		w_v[3] = b2Vec2(-48.284f, 20.0f);
		w_v[2] = b2Vec2(-48.698f, 21.0f);
		w_v[1] = b2Vec2(-69.284f, 21.0f);
		w_v[0] = b2Vec2(-69.284f, 20.0f);
		DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));

		w_v[3] = b2Vec2(-68.284f, -21.0f);
		w_v[2] = b2Vec2(-68.284f, 21.0f);
		w_v[1] = b2Vec2(-69.284f, 21.0f);
		w_v[0] = b2Vec2(-69.284f, -21.0f);
		DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));

		w_v[3] = b2Vec2(-48.698f, -21.0f);
		w_v[2] = b2Vec2(-48.284f, -20.0f);
		w_v[1] = b2Vec2(-69.284f, -20.0f);
		w_v[0] = b2Vec2(-69.284f, -21.0f);
		DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));

		w_v[3] = b2Vec2(-20.414f, -49.284f);
		w_v[2] = b2Vec2(-20.0f, -48.284f);
		w_v[1] = b2Vec2(-48.284f, -20.0f);
		w_v[0] = b2Vec2(-48.698f, -21.0f);
		DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));

		w_v[3] = b2Vec2(20.414f, -49.284f);
		w_v[2] = b2Vec2(20.0f, -48.284f);
		w_v[1] = b2Vec2(-20.0f, -48.284f);
		w_v[0] = b2Vec2(-20.414f, -49.284f);
		DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));

		w_v[3] = b2Vec2(48.698f, -21.0f);
		w_v[2] = b2Vec2(48.284f, -20.0f);
		w_v[1] = b2Vec2(20.0f, -48.284f);
		w_v[0] = b2Vec2(20.414f, -49.284f);
		DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));

		w_v[3] = b2Vec2(48.698f, -21.0f);
		w_v[2] = b2Vec2(69.284f, -21.0f);
		w_v[1] = b2Vec2(69.284f, -20.0f);
		w_v[0] = b2Vec2(48.284f, -20.0f);
		DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));

		w_v[3] = b2Vec2(68.284f, -21.0f);
		w_v[2] = b2Vec2(69.284f, -21.0f);
		w_v[1] = b2Vec2(69.284f, 21.0f);
		w_v[0] = b2Vec2(68.284f, 21.0f);
		DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));

		// field
		w_v[7] = b2Vec2(48.284f, 20.0f);
		w_v[6] = b2Vec2(20.0f, 48.284f);
		w_v[5] = b2Vec2(-20.0f, 48.284f);
		w_v[4] = b2Vec2(-48.284f, 20.0f);
		w_v[3] = b2Vec2(-48.284f, -20.0f);
		w_v[2] = b2Vec2(-20.0f, -48.284f);
		w_v[1] = b2Vec2(20.0f, -48.284f);
		w_v[0] = b2Vec2(48.284f, -20.0f);
		DrawSolidPolygon(w_v, 8, b2Color(0.8, 0.8, 0.8));

		// nest_resource
		w_v[3] = b2Vec2(-48.284f, 20.0f);
		w_v[2] = b2Vec2(-68.284f, 20.0f);
		w_v[1] = b2Vec2(-68.284f, -20.0f);
		w_v[0] = b2Vec2(-48.284f, -20.0f);
		DrawSolidPolygon(w_v, 4, b2Color(0.69, 0.79, 0.69));

		// nest_resource
		w_v[3] = b2Vec2(48.284f, 20.0f);
		w_v[2] = b2Vec2(48.284f, -20.0f);
		w_v[1] = b2Vec2(68.284f, -20.0f);
		w_v[0] = b2Vec2(68.284f, 20.0f);
		DrawSolidPolygon(w_v, 4, b2Color(1.0, 0.75, 0.55));

		// barriers
		{
			if(m_scenemgr->CountNodesByTag(MAKE_TAG('b', 'a', 'r', 'r')) > 0) {
				for(auto package : m_scenemgr->GetNodesByTag(MAKE_TAG('b', 'a', 'r', 'r'))) {
					b2Color col = b2Color(0.2f, 0.2f, 0.2f);
					b2Body* bd = static_cast<Block*>(package)->GetBody();
					w_v[3] = bd->GetWorldPoint(b2Vec2(0.3f, 2.5f));
					w_v[2] = bd->GetWorldPoint(b2Vec2(-0.3f, 2.5f));
					w_v[1] = bd->GetWorldPoint(b2Vec2(-0.3f, -2.5f));
					w_v[0] = bd->GetWorldPoint(b2Vec2(0.3f, -2.5f));
					DrawSolidPolygon(w_v, 4, col);
				}
			}
		}

		// robots
		for(auto robot : m_scenemgr->GetNodesByTag(MAKE_TAG('r', 'o', 'b', 'o'))) {
			b2Body* bd1 = static_cast<J0_A_Robot*>(robot)->m_motor[0]->GetBody();
			w_v[0] = bd1->GetWorldPoint(b2Vec2(-0.25, -0.1));
			w_v[1] = bd1->GetWorldPoint(b2Vec2(0.25, -0.1));
			w_v[2] = bd1->GetWorldPoint(b2Vec2(0.25, 0.1));
			w_v[3] = bd1->GetWorldPoint(b2Vec2(-0.25, 0.1));
			DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));
			b2Body* bd2 = static_cast<J0_A_Robot*>(robot)->m_motor[1]->GetBody();
			w_v[0] = bd2->GetWorldPoint(b2Vec2(-0.25, -0.1));
			w_v[1] = bd2->GetWorldPoint(b2Vec2(0.25, -0.1));
			w_v[2] = bd2->GetWorldPoint(b2Vec2(0.25, 0.1));
			w_v[3] = bd2->GetWorldPoint(b2Vec2(-0.25, 0.1));
			DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));
			b2Color col;
			switch(static_cast<J0_A_Robot*>(robot)->GetMode()) {
			case 1:
				col.Set(0.0f, 0.0f, 1.0f);
				break;
			case 2:
				col.Set(1.0f, 0.0f, 0.0f);
				break;
			case 3:
				col.Set(0.0f, 1.0f, 0.0f);
				break;
			default:
				col.Set(0.0f, 0.0f, 0.0f);
				break;
			}
 			DrawSolidCircle(static_cast<J0_A_Robot*>(robot)->GetMainComponent()->GetPosition(), 0.5f, col);

			if(robot->GetId()==0) {
				m_debugDraw.DrawCircle(static_cast<J0_A_Robot*>(robot)->GetMainComponent()->GetPosition(), 8.0f, b2Color(0.4,0.6,0.8));
			}
		}

		// resource
		if(m_scenemgr->CountNodesByTag(MAKE_TAG('r', 'e', 's', 'o')) > 0) {
			for(auto resource : m_scenemgr->GetNodesByTag(MAKE_TAG('r', 'e', 's', 'o'))) {
				b2Color col;
				if(resource->CheckFlag(CATCHED_FLAG)) {
					col.Set(0.7f, 0.0f, 0.7f);
				} else {
					col.Set(0.6,0.35,0.18);
				}
				DrawSolidCircle(static_cast<Block*>(resource)->GetPosition(), static_cast<Block*>(resource)->GetBody()->GetFixtureList()->GetShape()->m_radius, col);
			}
		}

		// package
		if(m_scenemgr->CountNodesByTag(MAKE_TAG('p', 'a', 'c', 'k')) > 0) {
			for(auto package : m_scenemgr->GetNodesByTag(MAKE_TAG('p', 'a', 'c', 'k'))) {
				b2Color col = b2Color(0.4f, 0.6f, 0.65f);
				b2Body* bd = static_cast<Block*>(package)->GetBody();
				w_v[3] = bd->GetWorldPoint(b2Vec2(2.5f, 3.75f));
				w_v[2] = bd->GetWorldPoint(b2Vec2(-2.5f, 3.75f));
				w_v[1] = bd->GetWorldPoint(b2Vec2(-2.5f, -3.75f));
				w_v[0] = bd->GetWorldPoint(b2Vec2(2.5f, -3.75f));
				DrawSolidPolygon(w_v, 4, col);
			}
		}
	}
	void Draw_W() {
			b2Vec2 w_v[10];

			// walls
			w_v[3] = b2Vec2(69.284f, 20.0f);
			w_v[2] = b2Vec2(69.284f, 21.0f);
			w_v[1] = b2Vec2(48.698f, 21.0f);
			w_v[0] = b2Vec2(48.284f, 20.0f);
			DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));

			w_v[3] = b2Vec2(48.284f, 20.0f);
			w_v[2] = b2Vec2(48.698f, 21.0f);
			w_v[1] = b2Vec2(20.414f, 49.284f);
			w_v[0] = b2Vec2(20.0f, 48.284f);
			DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));

			w_v[3] = b2Vec2(20.0f, 48.284f);
			w_v[2] = b2Vec2(20.414f, 49.284f);
			w_v[1] = b2Vec2(-20.414f, 49.284f);
			w_v[0] = b2Vec2(-20.0f, 48.284f);
			DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));

			w_v[3] = b2Vec2(-20.0f, 48.284f);
			w_v[2] = b2Vec2(-20.414f, 49.284f);
			w_v[1] = b2Vec2(-48.698f, 21.0f);
			w_v[0] = b2Vec2(-48.284f, 20.0f);
			DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));

			w_v[3] = b2Vec2(-48.284f, 20.0f);
			w_v[2] = b2Vec2(-48.698f, 21.0f);
			w_v[1] = b2Vec2(-69.284f, 21.0f);
			w_v[0] = b2Vec2(-69.284f, 20.0f);
			DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));

			w_v[3] = b2Vec2(-68.284f, -21.0f);
			w_v[2] = b2Vec2(-68.284f, 21.0f);
			w_v[1] = b2Vec2(-69.284f, 21.0f);
			w_v[0] = b2Vec2(-69.284f, -21.0f);
			DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));

			w_v[3] = b2Vec2(-48.698f, -21.0f);
			w_v[2] = b2Vec2(-48.284f, -20.0f);
			w_v[1] = b2Vec2(-69.284f, -20.0f);
			w_v[0] = b2Vec2(-69.284f, -21.0f);
			DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));

			w_v[3] = b2Vec2(-20.414f, -49.284f);
			w_v[2] = b2Vec2(-20.0f, -48.284f);
			w_v[1] = b2Vec2(-48.284f, -20.0f);
			w_v[0] = b2Vec2(-48.698f, -21.0f);
			DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));

			w_v[3] = b2Vec2(20.414f, -49.284f);
			w_v[2] = b2Vec2(20.0f, -48.284f);
			w_v[1] = b2Vec2(-20.0f, -48.284f);
			w_v[0] = b2Vec2(-20.414f, -49.284f);
			DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));

			w_v[3] = b2Vec2(48.698f, -21.0f);
			w_v[2] = b2Vec2(48.284f, -20.0f);
			w_v[1] = b2Vec2(20.0f, -48.284f);
			w_v[0] = b2Vec2(20.414f, -49.284f);
			DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));

			w_v[3] = b2Vec2(48.698f, -21.0f);
			w_v[2] = b2Vec2(69.284f, -21.0f);
			w_v[1] = b2Vec2(69.284f, -20.0f);
			w_v[0] = b2Vec2(48.284f, -20.0f);
			DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));

			w_v[3] = b2Vec2(68.284f, -21.0f);
			w_v[2] = b2Vec2(69.284f, -21.0f);
			w_v[1] = b2Vec2(69.284f, 21.0f);
			w_v[0] = b2Vec2(68.284f, 21.0f);
			DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));

			// field
			w_v[7] = b2Vec2(48.284f, 20.0f);
			w_v[6] = b2Vec2(20.0f, 48.284f);
			w_v[5] = b2Vec2(-20.0f, 48.284f);
			w_v[4] = b2Vec2(-48.284f, 20.0f);
			w_v[3] = b2Vec2(-48.284f, -20.0f);
			w_v[2] = b2Vec2(-20.0f, -48.284f);
			w_v[1] = b2Vec2(20.0f, -48.284f);
			w_v[0] = b2Vec2(48.284f, -20.0f);
			DrawSolidPolygon(w_v, 8, b2Color(0.8, 0.8, 0.8));

			// nest_resource
			w_v[3] = b2Vec2(-48.284f, 20.0f);
			w_v[2] = b2Vec2(-68.284f, 20.0f);
			w_v[1] = b2Vec2(-68.284f, -20.0f);
			w_v[0] = b2Vec2(-48.284f, -20.0f);
			DrawSolidPolygon(w_v, 4, b2Color(0.69, 0.79, 0.69));

			// nest_resource
			w_v[3] = b2Vec2(48.284f, 20.0f);
			w_v[2] = b2Vec2(48.284f, -20.0f);
			w_v[1] = b2Vec2(68.284f, -20.0f);
			w_v[0] = b2Vec2(68.284f, 20.0f);
			DrawSolidPolygon(w_v, 4, b2Color(1.0, 0.75, 0.55));

			// barriers
			{
				if(m_scenemgr->CountNodesByTag(MAKE_TAG('b', 'a', 'r', 'r')) > 0) {
					for(auto package : m_scenemgr->GetNodesByTag(MAKE_TAG('b', 'a', 'r', 'r'))) {
						b2Color col = b2Color(0.2f, 0.2f, 0.2f);
						b2Body* bd = static_cast<Block*>(package)->GetBody();
						w_v[3] = bd->GetWorldPoint(b2Vec2(0.3f, 2.5f));
						w_v[2] = bd->GetWorldPoint(b2Vec2(-0.3f, 2.5f));
						w_v[1] = bd->GetWorldPoint(b2Vec2(-0.3f, -2.5f));
						w_v[0] = bd->GetWorldPoint(b2Vec2(0.3f, -2.5f));
						DrawSolidPolygon(w_v, 4, col);
					}
				}
			}

			// robots
			for(auto robot : m_scenemgr->GetNodesByTag(MAKE_TAG('r', 'o', 'b', 'o'))) {
				b2Body* bd1 = static_cast<J0_A_Robot_S*>(robot)->m_motor[0]->GetBody();
				w_v[0] = bd1->GetWorldPoint(b2Vec2(-0.25, -0.1));
				w_v[1] = bd1->GetWorldPoint(b2Vec2(0.25, -0.1));
				w_v[2] = bd1->GetWorldPoint(b2Vec2(0.25, 0.1));
				w_v[3] = bd1->GetWorldPoint(b2Vec2(-0.25, 0.1));
				DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));
				b2Body* bd2 = static_cast<J0_A_Robot_S*>(robot)->m_motor[1]->GetBody();
				w_v[0] = bd2->GetWorldPoint(b2Vec2(-0.25, -0.1));
				w_v[1] = bd2->GetWorldPoint(b2Vec2(0.25, -0.1));
				w_v[2] = bd2->GetWorldPoint(b2Vec2(0.25, 0.1));
				w_v[3] = bd2->GetWorldPoint(b2Vec2(-0.25, 0.1));
				DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));
				b2Color col(1.0f, 1.0f, 0.0f);

	 			DrawSolidCircle(static_cast<J0_A_Robot_S*>(robot)->GetMainComponent()->GetPosition(), 0.5f, col);

				if(robot->GetId()==0) {
					m_debugDraw.DrawCircle(static_cast<J0_A_Robot_S*>(robot)->GetMainComponent()->GetPosition(), 8.0f, b2Color(0.4,0.6,0.8));
				}
			}

			// resource
			if(m_scenemgr->CountNodesByTag(MAKE_TAG('r', 'e', 's', 'o')) > 0) {
				for(auto resource : m_scenemgr->GetNodesByTag(MAKE_TAG('r', 'e', 's', 'o'))) {
					b2Color col;
					if(resource->CheckFlag(CATCHED_FLAG)) {
						col.Set(0.7f, 0.0f, 0.7f);
					} else {
						col.Set(0.6,0.35,0.18);
					}
					DrawSolidCircle(static_cast<Block*>(resource)->GetPosition(), static_cast<Block*>(resource)->GetBody()->GetFixtureList()->GetShape()->m_radius, col);
				}
			}

			// package
			if(m_scenemgr->CountNodesByTag(MAKE_TAG('p', 'a', 'c', 'k')) > 0) {
				for(auto package : m_scenemgr->GetNodesByTag(MAKE_TAG('p', 'a', 'c', 'k'))) {
					b2Color col = b2Color(0.4f, 0.6f, 0.65f);
					b2Body* bd = static_cast<Block*>(package)->GetBody();
					w_v[3] = bd->GetWorldPoint(b2Vec2(2.5f, 3.75f));
					w_v[2] = bd->GetWorldPoint(b2Vec2(-2.5f, 3.75f));
					w_v[1] = bd->GetWorldPoint(b2Vec2(-2.5f, -3.75f));
					w_v[0] = bd->GetWorldPoint(b2Vec2(2.5f, -3.75f));
					DrawSolidPolygon(w_v, 4, col);
				}
			}
		}
};

#endif /* REPLAY_H_ */
