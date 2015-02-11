package is.ru.tgra.objects;

import com.badlogic.gdx.graphics.g2d.BitmapFont;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;

/**
 * Keeps scores and highscores
 * @author DrepAri
 *
 */
public class Score {
	
	public int highscore;
	public int score;
	public String scoreName;
	public BitmapFont bitMap;
    public SpriteBatch batch;
    
    public Score() {
		score = 0;
		highscore = 0;
	    scoreName = "score: 0";
	    bitMap = new BitmapFont();
	    batch = new SpriteBatch();
    }
    
    public void update() {
		score++;
		scoreName = "score: " + score + " Highscore: " + highscore;
    }
    
    public void reset() {
    	if (score > highscore ) {
    		highscore = score;
    		scoreName = "score: " + score + " GAME OVER! NEW HIGHSCORE " + highscore;
    	}
    	scoreName = "score: " + score + " GAME OVER! HIGHSCORE " + highscore;
    	score = 0;
    }
}
