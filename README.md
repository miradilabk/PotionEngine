# PotionEngine

a simple GameObject-Component based 2d game engine based on OpenGL.

opengl3.2 and [GLFW ]([https://github.com/glfw/glfw])(https://github.com/glfw/glfw)needed to run this project. 

## useage

```cpp
//main.cpp
int main() {
    //create a GameWindow class with specified width and height, a GameWindow class can contain multiple scene
    GameWindow game(800, 600);
    //then create a scene, a Scene class can contain multiple GameObjects
    Scene scene;
    //then we can create a gameobject with default constructor, which make the gameobject positioned at (0,0), size 10*10 pixels
    GameObject gameObject;
    //we can also create a gameobject with a certain position, size, rotation and draw order(must be negative).
    //the background GameObject should be matching game size, and draw before everything.

	GameObject background(Transform2D(glm::vec2(0, 0), glm::vec2(800, 600), 180), -1);
	//but a gameobject is useless with no component attached to it, so we create a component, much like unity's MonoBehavior
	//SpriteRenderer class is a subclass of Component which renders a certain image file
	SpriteRenderer renderer("somePng.png");
    //then we attach SpriteRenderer component to the gameObject we created
    gameObject.AddComponent(&renderer);
    //add gameobject to the scene
    scene.AddGameObject(gameObject);
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

//Start is called when this component is attached to a gameobject
void Rotator::Start()
{
}

//Update is called every frame when attached to a gameobject
void Rotator::Update()
{
	transform->rotation += 0.1f;
}
```

#### some tips

- derive from Scene class and GameObject class to add more behavior.

- use game.deltaTime to get deltaTime.

- when specifying draw order in GameObject's constructor, the order must be unique between gameObjects and must be negative or a very large integer.



## TODO

- [ ] add collision component

- [ ] gravity

- [ ] trigger

- [ ] UI layer

- [ ] audio management

- [ ] input handling

- [ ] data management






