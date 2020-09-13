#include <bangtal.h>

using namespace bangtal;

int main()
{

	auto scene1 = Scene::create("E", "images/룸E.png");			//장면 생성
	auto scene2 = Scene::create("S", "images/룸S.png");
	auto scene3 = Scene::create("C", "images/룸C.png");
	auto scene4 = Scene::create("A", "images/룸A.png");
	auto scene5 = Scene::create("P", "images/룸P.png");
	auto scene6 = Scene::create("", "images/룸E.png"); 


	auto door1 = Object::create("images/룸E-문.png", scene1, 121, 84);	// 문 생성
	auto door2 = Object::create("images/룸S-문.png", scene2, 20, 290);
	auto door3 = Object::create("images/룸C-문.png", scene3, 20, 290);
	auto door4 = Object::create("images/룸A-문.png", scene4, 440, 238);
	auto door5 = Object::create("images/룸P-문.png", scene5, 425, 195);
	auto door6 = Object::create("images/룸E-문.png", scene6, 121, 84);


	auto snake = Object::create("images/snake.png", scene2, 600, 600);	// 룸S 아이템

	snake->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		
		snake->pick();
		return true;
	});

	auto Youcandoit = Object::create("images/Youcandoit.png", scene3, 780, 390);	// 룸C 오브젝트

	auto C = Object::create("images/C.png", scene3, 837, 540);	// 룸C 아이템

	C->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		C->pick();
		return true;
	});


	auto Apple = Object::create("images/Apple.png", scene4,1100, 450);	// 룸A 아이템

	Apple->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		Apple->pick();
		return true;
	});


	


	auto P = Object::create("images/P.png", scene5, 400, 200);	// 룸P 아이템

	P->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		P->pick();
		return true;
	});


	auto Picasso = Object::create("images/Picasso.jpg", scene5, 400, 200);	// 룸P 오브젝트


	auto E = Object::create("images/E.png", scene6, 120, 680);	// 룸E 아이템

	E->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		E->pick();
		return true;
	});

	showMessage("여긴 어디지.. 분명히 난 침대에서 잠들었을텐데");

	door1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene2->enter();
		return true;
	});

	door2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (snake->isHanded()) {
			scene3->enter();
		}
		else {
			scene2->enter();
			showMessage("문이 안열리잖아.. 뭔가 비밀이 숨겨져있나?");
		}

		return true;
	});

	door3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (C->isHanded()) {
			scene4->enter();
		}
		else {
			scene3->enter();
			showMessage("방 안을 살펴보자");
		}
		
		return true;
	});

	door4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (Apple->isHanded()) {
			scene5->enter();
		}
		else {
			scene4->enter();
			showMessage("방 안을 살펴보자");
		}

		return true;
	});

	door5->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (P->isHanded()) {
			scene6->enter();
			showMessage("여긴 처음에 깼던 방 아닌가? 뭐가 어떻게 된거지?");
		}
		else {
			scene5->enter();
			showMessage("방 안을 살펴보자");
		}

		return true;
	});

	door6->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (E->isHanded()) {
			endGame();
		}
		else {
			scene6->enter();
			showMessage("분명히 탈출할 방법이 있을거야");
		}
		
		return true;
	});


	Picasso->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (action == MouseAction::MOUSE_DRAG_LEFT) {
			Picasso->locate(scene5, 300, 200);
		}
		else if (action == MouseAction::MOUSE_DRAG_RIGHT)
		{
			Picasso->locate(scene5, 500, 200);
		}
		return true;
		});
	
	
		startGame(scene1);

		




	return 0;
		
}