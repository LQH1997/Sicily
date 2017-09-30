import static org.junit.Assert.*;
import org.junit.Test;

public class HelloWorldTest {
	public HelloWorld helloWorld = new HelloWorld();
	@Test
	public void testHello() {
		helloWorld.main();
		assertEquals("Hello World!",helloWorld.getStr());
	}
}