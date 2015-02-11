package is.ru.tgra;

import is.ru.tgra.objects.*;
import is.ru.tgra.util.Point2D;

import java.nio.FloatBuffer;
import java.util.ArrayList;
import java.util.List;

import com.badlogic.gdx.ApplicationListener;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Input;
import com.badlogic.gdx.graphics.GL11;
import com.badlogic.gdx.utils.BufferUtils;

public class WreckingBall implements ApplicationListener {

	int HEIGHT = 600;
	int WIDHT = 800;
	
	FloatBuffer boxVertexBuffer;
	FloatBuffer circleVertexBuffer;
	List<GameObject> objectList;
	Cannon cannon;
	CannonBall cannonBall;
	EndCircle endCircle;
	boolean isDragging;
	Score score;
	
	
	@Override
	public void create() {
		Gdx.gl11.glEnableClientState(GL11.GL_VERTEX_ARRAY);
		
		//Box shape
		boxVertexBuffer = BufferUtils.newFloatBuffer(8);
		boxVertexBuffer.put(new float[] {-25,-25, -25,25, 25,-25, 25,25});
		boxVertexBuffer.rewind();
		
		//circle shape
		circleVertexBuffer = BufferUtils.newFloatBuffer(50);
		for(float f = 0.0f; f < (2*Math.PI);  f += (2*Math.PI)/24 ) {
			circleVertexBuffer.put((float) Math.cos(f));
			circleVertexBuffer.put((float) Math.sin(f));	
		}
		circleVertexBuffer.rewind();
		
		isDragging = false;
		score = new Score();
		cannon = new Cannon(boxVertexBuffer);
		cannonBall = new CannonBall(circleVertexBuffer, cannon);
		endCircle = new EndCircle(circleVertexBuffer, cannonBall, score);
		
		objectList = new ArrayList<GameObject>();
		objectList.add(cannonBall);
		objectList.add(cannon);
		objectList.add(endCircle);
	
	}

	@Override
	public void dispose() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void pause() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void render() {
		update();
		display();	
	}
	
	public void update() {
		
		float deltaTime = Gdx.graphics.getDeltaTime();
		
		if(Gdx.input.isButtonPressed(Input.Buttons.LEFT) && !isDragging) {
			
			Point2D p = new Point2D(Gdx.input.getX(), (HEIGHT - Gdx.input.getY()));
			objectList.add(new Box(p, boxVertexBuffer, cannonBall));
			isDragging = true;
		}
		else if(Gdx.input.isButtonPressed(Input.Buttons.LEFT) && isDragging) {
			
			Box b = (Box) objectList.get(objectList.size() - 1);
			b.update(deltaTime);
		}
		else if(Gdx.input.isButtonPressed(Input.Buttons.RIGHT) && !isDragging) {
			
			Point2D p = new Point2D(Gdx.input.getX(), (HEIGHT - Gdx.input.getY()));
			objectList.add(new Line(p, cannonBall));
			isDragging = true;
		}
		else if(Gdx.input.isButtonPressed(Input.Buttons.RIGHT) && isDragging) {
			
			Line line = (Line) objectList.get(objectList.size() - 1);	
			line.update(deltaTime);
		}
		else {
			
			isDragging = false;
		}
		
		for(GameObject o : objectList) {
			if (o.checkCollision()) {
				score.update();
			}
		}
		
		if(endCircle.isGameOver) {
			objectList.subList(3, objectList.size()).clear();
		}
		
		cannon.update(deltaTime);
		cannonBall.update(deltaTime);
		
		// Game resets if the cannon ball is out of bounds
		if (cannonBall.pos.getX() >= WIDHT || cannonBall.pos.getY() >= HEIGHT
				|| cannonBall.pos.getX() < 0 || cannonBall.pos.getY() < 0) {
			score.reset();
			cannonBall.reset();
		}
	}
	
	public void display() {
		
		Gdx.gl11.glClearColor(0.5f, 0.5f, 0.9f, 0.7f);
		Gdx.gl11.glClear(GL11.GL_COLOR_BUFFER_BIT);
		Gdx.gl11.glMatrixMode(GL11.GL_MODELVIEW);
		Gdx.gl11.glLoadIdentity();
		Gdx.glu.gluOrtho2D(Gdx.gl11, 0, WIDHT, 0, HEIGHT);
		
		score.batch.begin();
		score.bitMap.setColor(1.0f, 1.0f, 1.0f, 1.0f);
		score.bitMap.draw(score.batch, score.scoreName, 25, 100); 
		score.batch.end();
		
		for (GameObject o : objectList) {
			o.draw();
		}
	}

	@Override
	public void resize(int arg0, int arg1) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void resume() {
		// TODO Auto-generated method stub
		
	}

}
