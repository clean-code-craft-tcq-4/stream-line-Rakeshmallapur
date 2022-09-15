package testsender;



import static org.junit.Assert.*;
import org.junit.Test;

import Sender.SenderData;
import Sender.SenderParameters;
import Sender.SenderService;
import Sender.SenderServiceImpl;


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
