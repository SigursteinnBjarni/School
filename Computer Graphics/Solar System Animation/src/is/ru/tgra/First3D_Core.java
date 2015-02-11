package is.ru.tgra;

import is.ru.tgra.objects.CelestialObject;
import is.ru.tgra.objects.Moon;
import is.ru.tgra.objects.Planet;
import is.ru.tgra.objects.Spaceship;
import is.ru.tgra.objects.Sphere;
import is.ru.tgra.objects.Star;
import is.ru.tgra.util.Camera;
import is.ru.tgra.util.Constants;
import is.ru.tgra.util.Point3D;
import is.ru.tgra.util.Vector3D;

import java.nio.FloatBuffer;
import java.util.ArrayList;
import java.util.List;



import com.badlogic.gdx.graphics.GL11;
import com.badlogic.gdx.utils.BufferUtils;
import com.badlogic.gdx.ApplicationListener;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Input;
import com.badlogic.gdx.InputProcessor;
import com.badlogic.gdx.audio.Music;



public class First3D_Core implements ApplicationListener, InputProcessor {
	private static int SCALER = 100;
	
	private List<CelestialObject> objectList;
	private Camera cam = null;
	private List<Float> animationTimes;

	Sphere space;
	private Spaceship spaceship;
	
	Music music;

	private FloatBuffer vertexBuffer2DBox;

	@Override
	public void create() {
		// This class implements input processor that we use
		// within this application listener.
		Gdx.input.setInputProcessor(this);

		Gdx.gl11.glEnable(GL11.GL_LIGHTING);
		Gdx.gl11.glEnable(GL11.GL_LIGHT0);
		Gdx.gl11.glEnable(GL11.GL_LIGHT1);
		Gdx.gl11.glShadeModel(GL11.GL_SMOOTH);

		Gdx.gl11.glEnable(GL11.GL_DEPTH_TEST);
		
		// background color
		Gdx.gl11.glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		

		Gdx.gl11.glMatrixMode(GL11.GL_PROJECTION);
		Gdx.gl11.glLoadIdentity();
		Gdx.glu.gluPerspective(Gdx.gl11, 90, 1.333333f, 0.2f, 10000000000f);

		Gdx.gl11.glEnableClientState(GL11.GL_VERTEX_ARRAY);

		music = Gdx.audio.newMusic(Gdx.files.internal("assets/sounds/Sound.mp3"));
		music.setLooping(true);
		music.play();
		
		
		cam = new Camera(new Point3D(0f, 0f, -(Constants.SUN_TO_JUPITER/(Constants.BASE_RADIUS * SCALER))), new Point3D(0.0f, 3.0f,
				-200f), new Vector3D(0.0f, 1.0f, 0.0f));
		
		objectList = new ArrayList<CelestialObject>();

		//SPACE
		space = new Sphere (24, 48, "assets/textures/Milky.png");

		Gdx.gl11.glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		Gdx.gl11.glMatrixMode(GL11.GL_PROJECTION);
		Gdx.gl11.glLoadIdentity();
		Gdx.glu.gluPerspective(Gdx.gl11, 90, 1.333333f, 0.2f, 1000000f);

		Gdx.gl11.glEnableClientState(GL11.GL_VERTEX_ARRAY);
		
		vertexBuffer2DBox = BufferUtils.newFloatBuffer(8);
		vertexBuffer2DBox.put(new float[] {0,0, 0,1, 1,0, 1,1});
		vertexBuffer2DBox.rewind();
		
		//SPACESHIP
		animationTimes = generateAnimationTimes();
		spaceship = new Spaceship(generateAnimationPoints(), animationTimes, 5);
		
		cam = new Camera(new Point3D(spaceship.getPosition().x, spaceship.getPosition().y, spaceship.getPosition().z), new Point3D(0.0f, 0.0f,
				-1f), new Vector3D(0.0f, 1.0f, 0.0f));
		
		
		//CELESTIAL OBJECTS
		objectList = new ArrayList<CelestialObject>();
		
		// SUN
		Star sun = new Star("assets/textures/SunMap.jpg", 0, 0, 0, 0, 
				Constants.SUN_RADIUS/(Constants.BASE_RADIUS * 4));
		objectList.add(sun);
		
		//MERCURY
		Planet mercury = new Planet("assets/textures/Mercury.jpg", 0, 0, 0 ,0, 
				Constants.MERCURY_RADIUS/Constants.BASE_RADIUS, Constants.SUN_TO_MERCURY/(Constants.BASE_RADIUS * SCALER));
		objectList.add(mercury);
		
		//VENUS
		Planet venus = new Planet("assets/textures/Venus.jpg", 0, 0, 0 ,0, 
				Constants.VENUS_RADIUS/Constants.BASE_RADIUS, Constants.SUN_TO_VENUS/(Constants.BASE_RADIUS * SCALER));
		objectList.add(venus);
		
		//EARTH
		Planet earth = new Planet("assets/textures/earthCloude.jpg", 0, 0, 0, 0,
				Constants.EARTH_RADIUS/Constants.BASE_RADIUS, Constants.SUN_TO_EARTH/(Constants.BASE_RADIUS * SCALER));
		earth.moons.add(new Moon("assets/textures/Moon.jpg", 0, 0, 0, 0, 
				Constants.MOON_RADIUS/(Constants.EARTH_RADIUS *1.3f)));
		objectList.add(earth);
		
		//MARS
		Planet mars = new Planet("assets/textures/Mars.jpg", 0, 0, 0 ,0, 
				Constants.MARS_RADIUS/Constants.BASE_RADIUS, Constants.SUN_TO_MARS/(Constants.BASE_RADIUS * SCALER));

		mars.moons.add(new Moon("assets/textures/Phobos.jpg", 0, 0, 0, 0, 
				Constants.PHOBOS_RADIUS/Constants.MARS_RADIUS));
		objectList.add(mars);
		
		//JUPITER
		Planet jupiter = new Planet("assets/textures/Jupiter.jpg", 0, 0, 0 ,0, 
				Constants.JUPITER_RADIUS/Constants.BASE_RADIUS, Constants.SUN_TO_JUPITER/(Constants.BASE_RADIUS * SCALER));
		
		jupiter.moons.add(new Moon("assets/textures/io.jpg", 0, 0, 0, 0,
						Constants.IO_RADIUS/(Constants.JUPITER_RADIUS * 1.3f)));
		jupiter.moons.add(new Moon("assets/textures/Europa.jpg", -50f, 10.0f, 10.0f, 0,
						Constants.EUROPA_RADIUS/(Constants.JUPITER_RADIUS * 1.3f)));
		jupiter.moons.add(new Moon("assets/textures/Ganymede.jpg", -100f, 10.0f, 10.0f, 0,
						Constants.GANYMEDE_RADIUS/(Constants.JUPITER_RADIUS * 1.3f)));
		jupiter.moons.add(new Moon("assets/textures/Callisto.jpg", -150f, 10.0f, 10.0f, 0,
						Constants.CALLISTO_RADIUS/(Constants.JUPITER_RADIUS * 1.3f)));
		
		objectList.add(jupiter);
		
		//SATURN
		Planet saturn = new Planet("assets/textures/Saturn.jpg", 0, 0, 0 ,0, 
				Constants.SATURN_RADIUS/Constants.BASE_RADIUS, Constants.SUN_TO_SATURN/(Constants.BASE_RADIUS * SCALER));

		
		saturn.moons.add(new Moon("assets/textures/Titan.jpg", 0, 0, 0, 0,
					Constants.TITAN_RADIUS/(Constants.SATURN_RADIUS * 1.3f)));
		saturn.moons.add(new Moon("assets/textures/Enceladus.jpg", -50f, 10.0f, 10.0f, 0,
				Constants.ENCELADUS_RADIUS/(Constants.SATURN_RADIUS * 1.3f))); 

		objectList.add(saturn);
		
		//URANUS                                                                            HEH
		Planet uranus = new Planet("assets/textures/Uranus.jpg", 0, 0, 0 ,0, 
				Constants.URANUS_RADIUS/Constants.BASE_RADIUS, Constants.SUN_TO_URANUS/(Constants.BASE_RADIUS * SCALER));
		
		uranus.moons.add(new Moon("assets/textures/Titania.jpg",0,0,0,0,
				Constants.TITANIA_RADIUS/(Constants.URANUS_RADIUS * 1.3f)));
		
		objectList.add(uranus);
		
		//NEPTUNE
		Planet neptune = new Planet("assets/textures/Neptune.jpg", 0, 0, 0 ,0, 
				Constants.NEPTUNE_RADIUS/Constants.BASE_RADIUS, Constants.SUN_TO_NEPTUNE/(Constants.BASE_RADIUS * SCALER));
		objectList.add(neptune);
		
		//PLUTO
		Planet pluto = new Planet("assets/textures/Pluto.jpg", 0, 0, 0 ,0, 
				Constants.PLUTO_RADIUS/Constants.BASE_RADIUS, Constants.SUN_TO_PLUTO/(Constants.BASE_RADIUS * SCALER));
		objectList.add(pluto);
	}

	@Override
	public void dispose() {
		// TODO Auto-generated method stub

	}

	@Override
	public void pause() {
		// TODO Auto-generated method stub

	}

	private float elapsedTime = 0;
	private void update() {

		float deltaTime = Gdx.graphics.getDeltaTime();
		elapsedTime += deltaTime;
		for (CelestialObject object : objectList) {
			object.update(deltaTime);
		}
		
		Point3D center;
		if (elapsedTime < animationTimes.get(0)/2) {
			center = new Point3D(0, 0, -((Planet) objectList.get(1)).getLengthFromStar());
		}
		else if (elapsedTime < (animationTimes.get(0) + animationTimes.get(1))/2) {
			center = new Point3D(0, 0, -((Planet) objectList.get(2)).getLengthFromStar());
		}
		else if (elapsedTime < (animationTimes.get(1) + animationTimes.get(2))/2) {
			center = new Point3D(0, 0, -((Planet) objectList.get(3)).getLengthFromStar());
		}
		else if (elapsedTime < (animationTimes.get(2) + animationTimes.get(3))/2) {
			center = new Point3D(0, 0, -((Planet) objectList.get(4)).getLengthFromStar());
		}
		else if (elapsedTime < (animationTimes.get(3) + animationTimes.get(4))/2) {
			center = new Point3D(0, 0, -((Planet) objectList.get(5)).getLengthFromStar());
		}
		else if (elapsedTime < (animationTimes.get(4) + animationTimes.get(5))/2) {
			center = new Point3D(0, 0, -((Planet) objectList.get(6)).getLengthFromStar());
		}
		else if (elapsedTime < (animationTimes.get(5) + animationTimes.get(6))/2) {
			center = new Point3D(0, 0, -((Planet) objectList.get(7)).getLengthFromStar());
		}
		else {
			center = new Point3D(0, 0, -((Planet) objectList.get(8)).getLengthFromStar());
		}
		
		cam.setModelViewMatrix();
	    cam.lookAt(new Point3D(spaceship.getPosition().x, spaceship.getPosition().y, spaceship.getPosition().z + 20), center, new Vector3D(0, 1, 0));

		spaceship.update(deltaTime, elapsedTime);
		
		if (Gdx.input.isKeyPressed(Input.Keys.UP))
			cam.pitch(-90.0f * deltaTime);

		if (Gdx.input.isKeyPressed(Input.Keys.DOWN))
			cam.pitch(90.0f * deltaTime);

		if (Gdx.input.isKeyPressed(Input.Keys.LEFT))
			cam.yaw(-90.0f * deltaTime);

		if (Gdx.input.isKeyPressed(Input.Keys.RIGHT))
			cam.yaw(90.0f * deltaTime);

		if (Gdx.input.isKeyPressed(Input.Keys.W))
			cam.slide(0.0f, 0.0f, -500.0f * deltaTime);

		if (Gdx.input.isKeyPressed(Input.Keys.S))
			cam.slide(0.0f, 0.0f, 500.0f * deltaTime);

		if (Gdx.input.isKeyPressed(Input.Keys.A))
			cam.slide(-500.0f * deltaTime, 0.0f, 0.0f);

		if (Gdx.input.isKeyPressed(Input.Keys.D))
			cam.slide(500.0f * deltaTime, 0.0f, 0.0f);

		if (Gdx.input.isKeyPressed(Input.Keys.R))
			cam.slide(0.0f, 500.0f * deltaTime, 0.0f);

		if (Gdx.input.isKeyPressed(Input.Keys.F))
			cam.slide(0.0f, -500.0f * deltaTime, 0.0f);
		
	}

	private void display() {
       Gdx.gl11.glClear(GL11.GL_COLOR_BUFFER_BIT|GL11.GL_DEPTH_BUFFER_BIT);
       
		// Configure light 0
		Gdx.gl11.glLightfv(GL11.GL_LIGHT0, GL11.GL_SPECULAR, new float[] { 100f,
				100f, 100f, 1.0f }, 0);
		Gdx.gl11.glLightfv(GL11.GL_LIGHT0, GL11.GL_POSITION, new float[] {
				0f, 0f, 0f, 1.0f }, 0);
		
		// Configure light 1
		Gdx.gl11.glLightfv(GL11.GL_LIGHT1, GL11.GL_AMBIENT, new float[] { 0.8f,
				0.8f, 0.8f, 1.0f }, 0);

		// Set diffuse material.
		Gdx.gl11.glMaterialfv(GL11.GL_FRONT, GL11.GL_DIFFUSE, new float[] {
				1.0f, 1.0f, 1.0f, 1.0f }, 0);
		Gdx.gl11.glMaterialfv(GL11.GL_FRONT, GL11.GL_SPECULAR, new float[] {
				0.2f, .2f, .2f, 1.0f }, 0);
		Gdx.gl11.glMaterialf(GL11.GL_FRONT, GL11.GL_SHININESS, 100);
	
		Gdx.gl11.glPushMatrix();
		Gdx.gl11.glTranslatef(0, 0, spaceship.getPosition().z);
		Gdx.gl11.glScalef(25000, 25000, 25000);
		space.draw();
		Gdx.gl11.glPopMatrix();
	
		for (CelestialObject object : objectList) {
			object.draw();
		}
		
		spaceship.draw();

	}
	
	private List<Point3D> generateAnimationPoints() {
		List<Point3D> points = new ArrayList<Point3D>();
		points.add(new Point3D(22, 0, -106));
		points.add(new Point3D(-167, 0, -284));
		points.add(new Point3D(-140, 0, -380));
		points.add(new Point3D(50, 0, -428));
		points.add(new Point3D(-70, 0, -500));
		points.add(new Point3D(-43, 0, -580));
		points.add(new Point3D(30, 0, -610));
		points.add(new Point3D(-104, 0, -733));
		points.add(new Point3D(-106, 0, -872));
		points.add(new Point3D(5, 0, -940));
		points.add(new Point3D(-143, 0, -1150));
		points.add(new Point3D(-368, 0, -2550));
		points.add(new Point3D(180, 0, -3160));
		points.add(new Point3D(-610, 0, -4000));
		points.add(new Point3D(-816, 0, -5000));
		points.add(new Point3D(162, 0, -6000));
		points.add(new Point3D(-600, 0, -8000));
		points.add(new Point3D(-600, 0, -10500));
		points.add(new Point3D(80, 0, -12500));
		points.add(new Point3D(-1200, 0, -14600));
		points.add(new Point3D(-1200, 0, -16500));
		points.add(new Point3D(80, 0, -18500));
				
		return points;
	}
	
	private List<Float> generateAnimationTimes() {
		List<Float> times = new ArrayList<Float>();
		times.add(15f);
		times.add(30f);
		times.add(50f);
		times.add(70f);
		times.add(90f);
		times.add(110f);
		times.add(130f);
		
		return times;
	}

	@Override
	public void render() {
		update();
		display();
	}

	@Override
	public void resize(int arg0, int arg1) {
		// TODO Auto-generated method stub

	}

	@Override
	public void resume() {
		// TODO Auto-generated method stub

	}

	@Override
	public boolean keyDown(int arg0) {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean keyTyped(char arg0) {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean keyUp(int arg0) {
		
		if (Input.Keys.Q == arg0) {
			Gdx.app.exit();
		}

		return false;
	}

	@Override
	public boolean mouseMoved(int arg0, int arg1) {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean scrolled(int arg0) {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean touchDown(int arg0, int arg1, int arg2, int arg3) {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean touchDragged(int arg0, int arg1, int arg2) {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean touchUp(int arg0, int arg1, int arg2, int arg3) {
		// TODO Auto-generated method stub
		return false;
	}

	public boolean touchMoved(int arg0, int arg1) {
		// TODO Auto-generated method stub
		return false;
	}

}
