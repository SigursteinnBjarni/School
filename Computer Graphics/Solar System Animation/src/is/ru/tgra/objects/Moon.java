package is.ru.tgra.objects;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.GL11;

public class Moon extends CelestialObject{

	public Moon(String texture_path, float orbit_angle, float orbit_speed, float rotation_angle, float rotation_speed, float size) {
		super(texture_path, orbit_angle, orbit_speed, rotation_angle, rotation_speed, size);	
	}

	@Override
	public void draw() {
		Gdx.gl11.glPushMatrix();
		Gdx.gl11.glMaterialfv(GL11.GL_FRONT, GL11.GL_EMISSION, new float[] {
				0.1f, 0.1f, 0.1f, 1f}, 0);
		Gdx.gl11.glRotatef(orbit_angle, 0, 1, 0);
		Gdx.gl11.glTranslatef(0, 0, -5);
		Gdx.gl11.glRotatef(rotation_angle, 0, 1, 0);
		Gdx.gl11.glScalef(size, size, size);
		
		this.sphere.draw();
		
		Gdx.gl11.glPopMatrix();
		
	}

	@Override
	public void update(float deltaTime) {
		this.rotation_angle += deltaTime * 100;
		this.orbit_angle += deltaTime * 10;
		
	}

}
