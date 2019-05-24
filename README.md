# PotionEngine

a simple GameObject-Component based 2d game engine based on OpenGL.

opengl3.2 and [GLFW](https://github.com/miradilabk/PotionEngine) needed to run this project. 

## useage

```cpp
//main.cpp
int main() {
    //create a GameWindow class with specified width and height, a GameWindow class can contain multiple scene
	GameWindow game(800, 600);
	//then create a scene, a Scene class can contain multiple GameObjects
	Scene *scene = new Scene();
	//then we can create a gameobject with default constructor, which make the gameobject positioned at (0,0), size 10*10 pixels
	GameObject *gameObject = new GameObject();
	//we can also create a gameobject with a certain position, size, rotation and draw order(must be negative).
	//background image GameObject should be matching game size, and draw before everything.
	GameObject background(Transform2D(glm::vec2(0, 0), glm::vec2(800, 600), 180), -1);
	//but a gameobject is useless with no component attached to it, so we add a component to it, much like unity's MonoBehavior
	//SpriteRenderer is a subclass of Component which renders a certain image file
	SpriteRenderer *renderer = gameObject->AddComponent<SpriteRenderer>();
	//render a png file
	renderer->Init("face.png");
	//add gameobject to the scene
	scene->AddGameObject(gameObject);
	//add scene to the game
	game.AddScene(scene);
	//tell game which scene it should render(the first one)
	game.currentSceneIndex = 0;
	//at last start the game
	game.Start();
}
```

you can create your own component by deviring the Component class and overriding the Start() and Update() method, the Rotator class is a simple example of this which always rotates the gameObject :

```cpp
//Rotator.cpp
float rotateSpeed = 50f;
//Start is called when this component is attached to a gameobject
void Rotator::Start()
{
}

//Update is called every frame when attached to a gameobject
void Rotator::Update()
{
    transform->rotation += rotateSpeed*GameWindow::deltaTime;
}
```

#### some tips

- derive from Scene class and GameObject class to add more behavior, like the example breakOut game in code.

- use game.deltaTime to get deltaTime.

- when specifying draw order in GameObject's constructor, the order must be unique between gameObjects and must be negative or a very large integer.

- use Input::GetKeyDown(keycode) or GetKeyUp to handle inputs in Component's Update function, keycode should be GLFW_KEY_SOMEKEY.

## TODO

- [ ] add collision component

- [ ] gravity

- [ ] trigger

- [ ] UI layer

- [ ] audio management

- [x] input handling

- [ ] data management
