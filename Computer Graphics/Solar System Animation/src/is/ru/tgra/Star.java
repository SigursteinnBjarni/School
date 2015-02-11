package is.ru.tgra;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.GL11;

public class Star extends CelestialObject{

	public Star(String texture_path, float orbit_angle, float orbit_speed, float rotation_angle, float rotation_speed,
			float size) {
		super(texture_path, orbit_angle, orbit_speed, rotation_angle, rotation_speed, size);
	}

	@Override
	public void draw() {
		Gdx.gl11.glPushMatrix();
		Gdx.gl11.glMaterialfv(GL11.GL_FRONT, GL11.GL_EMISSION, new float[] {
				0.5f, 0.5f, 0.5f, 1f}, 0);
		Gdx.gl11.glRotatef(orbit_angle, 0, 1, 0);
		Gdx.gl11.glTranslatef(0, 0, 0);
		Gdx.gl11.glRotatef(rotation_angle, 0, 1, 0);
		Gdx.gl11.glScalef(size, size, size);
		
		sphere.draw();
		Gdx.gl11.glPopMatrix();
	}

	@Override
	public void update(float deltaTime) {
		// TODO Auto-generated method stub
		
	}

}
