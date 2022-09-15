package sender;

import java.util.List;

public interface SenderService {
		public List<SenderParameters> receiveReadingsFromBattery(int streamcount);
		public void sendReadingsToConsole();

}