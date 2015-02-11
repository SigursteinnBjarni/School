package is.ru.tgra;

import java.util.ArrayList;
import java.util.List;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.GL11;

public class Planet extends CelestialObject{
	
	public List<CelestialObject> moons = null;
	private float length_from_star;
	
	public Planet(String texture_path, float orbit_angle, float orbit_speed, float rotation_angle, float rotation_speed, float size, float length) {
		super(texture_path, orbit_angle, orbit_speed, rotation_angle, rotation_speed, size);
		
		this.length_from_star = length;
		this.moons = new ArrayList<CelestialObject>();
	}
	
	public void draw() {
		
		Gdx.gl11.glPushMatrix();
		Gdx.gl11.glMaterialfv(GL11.GL_FRONT, GL11.GL_EMISSION, new float[] {
				0.1f, 0.1f, 0.1f, 1f}, 0);
		Gdx.gl11.glRotatef(orbit_angle, 0, 1, 0);
		Gdx.gl11.glTranslatef(0, 0, -length_from_star);
		Gdx.gl11.glRotatef(rotation_angle, 0, 1, 0);
		Gdx.gl11.glScalef(size, size, size);
		for (CelestialObject moon : moons) {
			moon.draw();
		}
		sphere.draw();
		Gdx.gl11.glPopMatrix();
	}

	public void update(float deltaTime) {
		this.rotation_angle += deltaTime * 10;
		this.orbit_angle += deltaTime * orbit_speed;
		
	}

}
