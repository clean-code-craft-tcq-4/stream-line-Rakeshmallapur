package com.java.stream.line;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

public class SenderInput {
	private static Logger log = new Logger();

	public static void main(String[] args) {
		DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
		Date date = new Date();
		try {
			String noofEntries = "50";
			if (SenderData.checkNumeric(noofEntries) && SenderData.validateDataSize(noofEntries)) {
				log.setMessage("----------------" + dateFormat.format(date) + "----------------------------");
				log.setMessage("Input Data Size: " + noofEntries);
				SenderService data = new SenderServiceImpl();
				data.receiveReadingsFromBattery(Integer.parseInt(noofEntries));
				data.sendReadingsToConsole();
			}

		} catch (NullPointerException e) {
			System.out.println(e.getLocalizedMessage());
		}
	}

}
