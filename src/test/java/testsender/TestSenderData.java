package testsender;



import static org.junit.Assert.*;
import org.junit.Test;

import sender.SenderData;
import sender.SenderParameters;
import sender.SenderService;
import sender.SenderServiceImpl;


public class TestSenderData {

	
	@Test
	public void givenBatteryParametersAsNull() {
		SenderParameters batteryValue = null;
		assertNull(SenderData.isEmpty(batteryValue));
	}

	
	@Test
	public void givenBatteryParametersSizeisLessThan10() {
		assertFalse(SenderData.validateDataSize("8"));
	}

	
	@Test
	public void givenBatteryParamexpectspropercount() {
		SenderService sender = new SenderServiceImpl();
		int validateSize = 50;
		assertEquals(sender.receiveReadingsFromBattery(50).size(), validateSize);
		sender.sendReadingsToConsole();
	}

}
