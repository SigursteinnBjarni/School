package is.ru.tgra.objects;

import is.ru.tgra.util.Point2D;
import is.ru.tgra.util.Util;

import java.nio.FloatBuffer;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.GL11;
import com.badlogic.gdx.utils.BufferUtils;

/**
 * Line game object handles collisions and drawing itself
 * @author DrepAri
 *
 */
public class Line implements GameObject {

	public Point2D start;
	public Point2D end;
	public FloatBuffer vertexBuffer;
	public CannonBall cannonBall;
	
	public Line(Point2D p, CannonBall c) {
		start = p;
		cannonBall = c;
		end = new Point2D(p.getX(), p.getY());
		vertexBuffer = BufferUtils.newFloatBuffer(4);
	}
	@Override
	public void draw() {
		generateBuffer();
		Gdx.gl11.glPushMatrix();
		Gdx.gl11.glColor4f(0.2f, 0.3f, 0.8f, 1.0f);
		Gdx.gl11.glLineWidth(5f);
		Gdx.gl11.glVertexPointer(2, GL11.GL_FLOAT, 0, vertexBuffer);
		Gdx.gl11.glDrawArrays(GL11.GL_LINES, 0, 2);
		Gdx.gl11.glPopMatrix();
		
	}

	@Override
	public void update(float deltaTime) {
		
		end.setX((Gdx.input.getX()));
		end.setY((600 - Gdx.input.getY()));
		
	}

	/**
	 * checks on collisions based on thit and phit formulas
	 */
	@Override
	public boolean checkCollision() {
		
		if (cannonBall.isMoving) {
			float thit = Util.tHit(cannonBall.pos, start, cannonBall.movementVector, Util.normalVector(start, end));
			
			if (thit > 0 && thit <= 1) {
				Point2D p = Util.pHit(cannonBall.pos, cannonBall.movementVector, thit);
				
				if(Util.isBetween(start, end, p)) {
					cannonBall.movementVector = Util.collisionResponse(cannonBall.movementVector, Util.normalVector(start, end));
					System.out.println("MM vector: " + cannonBall.movementVector.getX() + ", " + cannonBall.movementVector.getY());
					return true;
				}
			}
		}
		return false;
	}
	
	private void generateBuffer() {
		vertexBuffer.clear();
		vertexBuffer.put(start.getX());
		vertexBuffer.put(start.getY());
		vertexBuffer.put(end.getX());
		vertexBuffer.put(end.getY());
		vertexBuffer.rewind();
	}

}
