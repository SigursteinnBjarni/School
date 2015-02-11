package is.ru.tgra;

import org.lwjgl.opengl.GL11;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.Mesh;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.Texture.TextureFilter;
import com.badlogic.gdx.graphics.g3d.StillModelInstance;
import com.badlogic.gdx.graphics.g3d.ModelLoaderHints;
import com.badlogic.gdx.graphics.g3d.loaders.ModelLoader;
import com.badlogic.gdx.graphics.g3d.loaders.wavefront.ObjLoader;
import com.badlogic.gdx.graphics.g3d.model.Model;
import com.badlogic.gdx.graphics.g3d.model.still.StillModel;



import is.ru.tgra.Point3D;

public class Spaceship {
	
	private Point3D position;
	private ObjLoader objLoader;
	private Model model;
	private Texture texture;
	private float rotation_angle;
	

	
	public Spaceship(Point3D startpos) {
		this.position = startpos;
		objLoader = new ObjLoader();
		model = objLoader.load(Gdx.files.internal("assets/models/Tardis.obj"), new ModelLoaderHints(true));
		texture = new Texture(Gdx.files.internal("assets/models/Tardis.jpg"));
	}
	
	public Point3D getPosition() {
		return this.position;
	}
	
	public void draw() {
		Gdx.gl11.glPushMatrix();
		Gdx.gl11.glTranslatef(position.x, position.y, position.z);
		Gdx.gl11.glRotatef(rotation_angle, 0, 1, 0);
		Gdx.gl11.glScalef(0.5f, 0.5f, 0.5f);
		Gdx.gl11.glEnable(GL11.GL_TEXTURE_2D);
		texture.bind();
		model.render();
		Gdx.gl11.glDisable(GL11.GL_TEXTURE_2D);
		Gdx.gl11.glPopMatrix();
	}
	
	public void update(float deltaTime) {
		this.rotation_angle += deltaTime * 100;
	}
	
}