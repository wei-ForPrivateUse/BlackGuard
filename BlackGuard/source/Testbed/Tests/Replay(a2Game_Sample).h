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

void Draw();

void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Color& color);
void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
void DrawString(int x, int y, const char *string, ...);
void DrawString(const b2Vec2& p, const char *string, ...);
void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);

class Replay_a2Game_Sample: public Test {
public:

	Replay_a2Game_Sample() {
		ANNWeights* arbi = new ANNWeights({6, 10, 3}, {false, true, false}, {false, true, true}, true);
		ANNWeights* w1 = new ANNWeights({19, 20, 2}, {false, true, false}, {false, true, true}, true);
		ANNWeights* w2 = new ANNWeights({14, 20, 2}, {false, true, false}, {false, true, true}, true);
		ANNWeights* w3 = new ANNWeights({11, 20, 2}, {false, true, false}, {false, true, true}, true);

		double w1_c[] = {};
		double w2_c[] = {};

		//w1->Set(w1_c);
		//w2->Set(w2_c);

		arbi->Randomize();
		w1->Randomize();
		w2->Randomize();
		w3->Randomize();

		J1_S_Field::Configuration conf;
		conf.World = m_world;
		conf.TrainingMode = 1;
		conf.Robot = 50;
		m_scenemgr = new J1_S_Field(&conf, arbi, w1, w2, w3);
	}

	void Step(Settings* settings) {
		std::cout<<m_stepCount<<":   ";
		Test::Step(settings);

		std::cout<<static_cast<J1_S_Field*>(m_scenemgr)->m_robot[0]->GetDataPool().Get<float>(40)<<"|"
					<<static_cast<J1_S_Field*>(m_scenemgr)->m_robot[0]->GetDataPool().Get<float>(41)<<"|"
						<<static_cast<J1_S_Field*>(m_scenemgr)->m_robot[0]->GetDataPool().Get<float>(42)<<" <----> ";
		std::cout<<static_cast<J1_S_Field*>(m_scenemgr)->m_robot[0]->m_a_s1->IsActive()<<", "
					<<static_cast<J1_S_Field*>(m_scenemgr)->m_robot[0]->m_a_s2->IsActive()<<", "
						<<static_cast<J1_S_Field*>(m_scenemgr)->m_robot[0]->m_a_s3->IsActive()<<" <----> ";
		std::cout<<static_cast<J1_S_Field*>(m_scenemgr)->m_robot[0]->GetMode();
		std::cout<<std::endl;

//		for(int i = 10; i <18; i++) {
//			std::cout<<static_cast<J1_S_Field*>(m_scenemgr)->m_robot[0]->GetDataPool().Get<float>(i)<<", ";
//		}

		Draw();
		DrawCircleNest(b2Vec2(0,0), 18, b2Color(0.8f, 0.8f, 0.8f));

		/////////////////
		float time = m_stepCount /60.0f;
		char buffer[50];
		sprintf(buffer, "Replay : %6.2fs / 200.00s", time);
		DrawString(50,100,buffer);
		/////////////////

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

	static Test* Create() {
		return new Replay_a2Game_Sample;
	}

	void Draw() {
		b2Vec2 w_v[10];
//		//walls
//		w_v[3] = b2Vec2(-55, -55);
//		w_v[2] = b2Vec2(-50, -55);
//		w_v[1] = b2Vec2(-50, 55);
//		w_v[0] = b2Vec2(-55, 55);
//		DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));
//
//		w_v[3] = b2Vec2(-55, -55);
//		w_v[2] = b2Vec2(55, -55);
//		w_v[1] = b2Vec2(55, -50);
//		w_v[0] = b2Vec2(-55, -50);
//		DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));
//
//		w_v[3] = b2Vec2(55, -55);
//		w_v[2] = b2Vec2(55, 55);
//		w_v[1] = b2Vec2(50, 55);
//		w_v[0] = b2Vec2(50, -55);
//		DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));
//
//		w_v[3] = b2Vec2(55, 55);
//		w_v[2] = b2Vec2(-55, 55);
//		w_v[1] = b2Vec2(-55, 50);
//		w_v[0] = b2Vec2(55, 50);
//		DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));
//
//		//food area
//		w_v[3] = b2Vec2(50, 50);
//		w_v[2] = b2Vec2(-50, 50);
//		w_v[1] = b2Vec2(-50, -50);
//		w_v[0] = b2Vec2(50, -50);
//		DrawSolidPolygon(w_v, 4, b2Color(0.7, 0.7, 0.7));
//
//		//nest
//		w_v[3] = b2Vec2(12, 12);
//		w_v[2] = b2Vec2(-12, 12);
//		w_v[1] = b2Vec2(-12, -12);
//		w_v[0] = b2Vec2(12, -12);
//		DrawSolidPolygon(w_v, 4, b2Color(0.5, 0.5, 0.5));

		//robots
		for(auto robot : m_scenemgr->GetNodesByTag(MAKE_TAG('r', 'o', 'b', 'o'))) {
			if(robot->GetId()==0) {
			b2Body* bd1 = static_cast<J1_A_Robot*>(robot)->m_motor[0]->GetBody();
			w_v[0] = bd1->GetWorldPoint(b2Vec2(-0.25, -0.1));
			w_v[1] = bd1->GetWorldPoint(b2Vec2(0.25, -0.1));
			w_v[2] = bd1->GetWorldPoint(b2Vec2(0.25, 0.1));
			w_v[3] = bd1->GetWorldPoint(b2Vec2(-0.25, 0.1));
			DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));
			b2Body* bd2 = static_cast<J1_A_Robot*>(robot)->m_motor[1]->GetBody();
			w_v[0] = bd2->GetWorldPoint(b2Vec2(-0.25, -0.1));
			w_v[1] = bd2->GetWorldPoint(b2Vec2(0.25, -0.1));
			w_v[2] = bd2->GetWorldPoint(b2Vec2(0.25, 0.1));
			w_v[3] = bd2->GetWorldPoint(b2Vec2(-0.25, 0.1));
			DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));
			DrawSolidCircle(static_cast<J1_A_Robot*>(robot)->GetMainComponent()->GetPosition(), 0.5f, b2Color(0.4,0.6,0.8));

			///
			m_debugDraw.DrawCircle(static_cast<J1_A_Robot*>(robot)->GetMainComponent()->GetPosition(), 12.0f, b2Color(0.4,0.6,0.8));
			}
		}

//		//poison
//		for(auto poison : m_scenemgr->GetNodesByTag(MAKE_TAG('p', 'o', 'i', 's'))) {
//			auto col = b2Color(0.8, 0.17, 0.17);
//			DrawSolidCircle(static_cast<Block*>(poison)->GetPosition(), static_cast<Block*>(poison)->GetBody()->GetFixtureList()->GetShape()->m_radius, col);
//		}
//
//		//resource
//		for(auto resource : m_scenemgr->GetNodesByTag(MAKE_TAG('r', 'e', 's', 'o'))) {
//			auto col = b2Color(0.2, 0.52, 0.3);
//			DrawSolidCircle(static_cast<Block*>(resource)->GetPosition(), static_cast<Block*>(resource)->GetBody()->GetFixtureList()->GetShape()->m_radius, col);
//		}
	}
};


/////
/////
/////
void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Color& color)
{
	const float32 k_segments = 16.0f;
	const float32 k_increment = 2.0f * b2_pi / k_segments;
	float32 theta = 0.0f;
	glEnable(GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(color.r, color.g, color.b, 1);
	glBegin(GL_TRIANGLE_FAN);
	for (int32 i = 0; i < k_segments; ++i)
	{
		b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));
		glVertex2f(v.x, v.y);
		theta += k_increment;
	}
	glEnd();
	glDisable(GL_BLEND);

	theta = 0.0f;
	glColor4f(color.r, color.g, color.b, 1);
	glBegin(GL_LINE_LOOP);
	for (int32 i = 0; i < k_segments; ++i)
	{
		b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));
		glVertex2f(v.x, v.y);
		theta += k_increment;
	}
	glEnd();
}

void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	glEnable(GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(color.r, color.g, color.b, 1);
	glBegin(GL_TRIANGLE_FAN);
	for (int32 i = 0; i < vertexCount; ++i)
	{
		glVertex2f(vertices[i].x, vertices[i].y);
	}
	glEnd();
	glDisable(GL_BLEND);

	glColor4f(color.r, color.g, color.b, 1);
	glBegin(GL_LINE_LOOP);
	for (int32 i = 0; i < vertexCount; ++i)
	{
		glVertex2f(vertices[i].x, vertices[i].y);
	}
	glEnd();
}

void DrawString(int x, int y, const char *string, ...)
{
	char buffer[128];

	va_list arg;
	va_start(arg, string);
	vsprintf(buffer, string, arg);
	va_end(arg);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	int w = glutGet(GLUT_WINDOW_WIDTH);
	int h = glutGet(GLUT_WINDOW_HEIGHT);
	gluOrtho2D(0, w, h, 0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glColor3f(0.9f, 0.6f, 0.6f);
	glRasterPos2i(x, y);
	int32 length = (int32)strlen(buffer);
	for (int32 i = 0; i < length; ++i)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, buffer[i]);
	}

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void DrawString(const b2Vec2& p, const char *string, ...)
{
	char buffer[128];

	va_list arg;
	va_start(arg, string);
	vsprintf(buffer, string, arg);
	va_end(arg);

	glColor3f(0.5f, 0.9f, 0.5f);
	glRasterPos2f(p.x, p.y);

	int32 length = (int32)strlen(buffer);
	for (int32 i = 0; i < length; ++i)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, buffer[i]);
	}

	glPopMatrix();
}

void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
{
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_LINES);
	glVertex2f(p1.x, p1.y);
	glVertex2f(p2.x, p2.y);
	glEnd();
}

#endif /* REPLAY_A2GAME_SAMPLE__H_ */
