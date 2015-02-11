package is.ru.tgra.objects;

import is.ru.tgra.util.Point2D;

import java.nio.FloatBuffer;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.GL11;

public class EndCircle implements GameObject {
	
	public float RADIUS = 40;
	public FloatBuffer vertexBuffer;
	public Point2D pos;
	public CannonBall cannonBall;
	public Score score;
    public boolean isGameOver;
	
	public EndCircle(FloatBuffer f, CannonBall cannonb, Score sc) {
		vertexBuffer = f;
		pos = randomCoords();
		cannonBall = cannonb;
		score = sc;
		
	}
	@Override
	public void draw() {
		
		Gdx.gl11.glPushMatrix();
		Gdx.gl11.glColor4f(0.2f, 0.5f, 0.2f, 1.0f);
		Gdx.gl11.glVertexPointer(2, GL11.GL_FLOAT, 0, vertexBuffer);
		Gdx.gl11.glTranslatef(pos.getX(), pos.getY(), 0);
		Gdx.gl11.glScalef(RADIUS, RADIUS, 0);
		Gdx.gl11.glDrawArrays(GL11.GL_TRIANGLE_FAN, 0, 24);
		Gdx.gl11.glPopMatrix();
		
	} 
	
	@Override
	public void update(float deltaTime) {
		
	}

	@Override
	public boolean checkCollision() {
		
		if (Math.pow(cannonBall.pos.getX() - pos.getX(), 2) + Math.pow(cannonBall.pos.getY() - pos.getY(), 2)
				< Math.pow(RADIUS, 2)) {
			score.reset();
			cannonBall.reset();
			pos = randomCoords();
			isGameOver = true;
			return false;
		}
		
		isGameOver = false;
		return false;
	}
	
	private Point2D randomCoords() {
		return new Point2D((float) Math.random() * 800, (float) (Math.random() * 400) + 200) ;
	}
}
