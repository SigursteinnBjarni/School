package is.ru.tgra;

import com.badlogic.gdx.ApplicationListener;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.GL11;
import com.badlogic.gdx.Input;
import com.badlogic.gdx.utils.BufferUtils;
import java.nio.FloatBuffer;

public class Boxes2 implements ApplicationListener {
	
	float position_y;
	float position_x;
	FloatBuffer vertexBuffer;
 @Override
 public void create() {
 // TODO Auto-generated method stub
	 
	 position_x = 100;
	 position_y = 100;
	 
	 Gdx.gl11.glEnableClientState(GL11.GL_VERTEX_ARRAY);
	 Gdx.gl11.glClearColor(0.4f, 0.6f, 1.0f, 1.0f);
	 
	 vertexBuffer = BufferUtils.newFloatBuffer(8);
	 vertexBuffer.put(new float[] {position_x,position_y,
			 position_x,position_y +100,
			 position_x+100,position_y,
			 position_x+100,position_y+100 });

	 vertexBuffer.rewind();
	 Gdx.gl11.glVertexPointer(2, GL11.GL_FLOAT, 0, vertexBuffer);
	 
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
 // TODO Auto-generated method stub
	 update();
	 display();
	 
 }
 
 public void display(){
	 Gdx.gl11.glClear(GL11.GL_COLOR_BUFFER_BIT);
	 Gdx.gl11.glMatrixMode(GL11.GL_MODELVIEW);
	 Gdx.gl11.glLoadIdentity();
	 
	 Gdx.glu.gluOrtho2D(Gdx.gl10, 0, 640, 0, 480);
	 Gdx.gl11.glColor4f(0.6f, 0.0f, 0.0f, 1.0f);
	 Gdx.gl11.glTranslatef(position_x, position_y, 0.0f);
	 Gdx.gl11.glVertexPointer(2, GL11.GL_FLOAT, 0, vertexBuffer);
	 Gdx.gl11.glDrawArrays(GL11.GL_TRIANGLE_STRIP, 0, 4);
	 
 }
 public void update(){
	 
	 if(Gdx.input.isKeyPressed(Input.Keys.LEFT)){
		 position_x -=2;
		 if(position_x <= -100){
			 position_x = -100;
		 }
	
	 }
	 if(Gdx.input.isKeyPressed(Input.Keys.RIGHT)){
		 position_x +=2;
		 if(position_x >= 440){
			 position_x = 440;
		 }
	 }
	 
	 if(Gdx.input.isKeyPressed(Input.Keys.UP)){
		 position_y +=2;
		 if(position_y >= 280){
			 position_y = 280;
		 }
	 }
	 
	 if(Gdx.input.isKeyPressed(Input.Keys.DOWN)){
		 position_y -=2;
		 if(position_y <= -100){
			 position_y = -100;
		 }
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