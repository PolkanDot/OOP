#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "../ArraySum/ArraySum.h"

SCENARIO("Checking the correctness of the overflow operation")
{
	WHEN("int overflow")
	{
		THEN("Return exeption")
		{
			std::vector<int> arr{ -2134567985, -956566345, -934534345 };
			try
			{
				int sum = ArraySum(arr);
			}
			catch (std::domain_error err)
			{
				std::string message = err.what();
				CHECK(message == errMessege);
			}
			
		}
	}

	WHEN("float overflow")
	{
		THEN("Return exeption")
		{
			std::vector<float> arr{ 3.40282e+38 , 3.40282e+38 };
			try
			{
				float sum = ArraySum(arr);
			}
			catch (std::domain_error err)
			{
				std::string message = err.what();
				CHECK(message == errMessege);
			}
		}
	}

	WHEN("double overflow")
	{
		THEN("Return exeption")
		{
			std::vector<double> arr{ 1.79769e+308, 1.79769e+308, 1.79769e+308 };
			try
			{
				double sum = ArraySum(arr);
			}
			catch (std::domain_error err)
			{
				std::string message = err.what();
				CHECK(message == errMessege);
			}
		}
	}
}

SCENARIO("Checking correct operation at maximum values")
{
	WHEN("int max values")
	{
		THEN("Return correct walue")
		{
			std::vector<int> arr{ -1134567985, -256566345, -234534345 };
			int sum = ArraySum(arr);
			CHECK(sum == -1625668675);
		}
	}

	WHEN("float max values")
	{
		THEN("Return correct walue")
		{
			std::vector<float> arr{ 1.40282e+38 , 1.40282e+38 };
			float sum = ArraySum(arr);
			CHECK(sum == 280563996181293893212318485738546003968.0f);
		}
	}

	WHEN("double max values")
	{
		THEN("Return correct walue")
		{
			std::vector<double> arr{ 0.59769e+308, 0.59769e+308, 0.59769e+308 };
			double sum = ArraySum(arr);
			CHECK(sum == 1.79307e+308);
		}
	}

	WHEN("big string vector")
	{
		THEN("Return correct walue")
		{
			std::vector<std::string> arr{ "ddfgdfgsgkdsfjgkdfghiuuerhidsjdfgpshgpiwejgdspfhghpuewrihgdpioghewrughdfsiughperwuipigh",
				"sdfiughpwerspovignevmidpiogbjpvsmisdflkgjsdf;",
				"lgjpoijpofhspijvnspguhseoknfsvoisdfhgosidpfvnpsokdnbs - iobjvpkbnpsdfiogdsgndfpbibnbsiodjb[i",
				"gdfodfsn[b]]bondigshpbx ojgsrhgsvjgheirtiovsopimgp"
				"odfhbddvnpmzgksdcforitvgpmi gs,dgjdfknmgcsegx fmkbjdpog jdp,ogjd pmkosdkghvmcgcmpovsngmsgfgmgcplkbgfmgkmndpfgdpjghn fgjnpxjx bnfgh" };
			std::string sum = ArraySum(arr);
			CHECK(sum == "ddfgdfgsgkdsfjgkdfghiuuerhidsjdfgpshgpiwejgdspfhghpuewrihgdpioghewrughdfsiughperwuipighsdfiughpwerspovignevmidpiogbjpvsmisdflkgjsdf;"
				"lgjpoijpofhspijvnspguhseoknfsvoisdfhgosidpfvnpsokdnbs - iobjvpkbnpsdfiogdsgndfpbibnbsiodjb[igdfodfsn[b]]bondigshpbx ojgsrhgsvjgheirtiovsopimgp"
				"odfhbddvnpmzgksdcforitvgpmi gs,dgjdfknmgcsegx fmkbjdpog jdp,ogjd pmkosdkghvmcgcmpovsngmsgfgmgcplkbgfmgkmndpfgdpjghn fgjnpxjx bnfgh");
		}
	}
	WHEN("very big string vector")
	{
		THEN("Return correct walue")
		{
			std::vector<std::string> arr{ "ddfgdfgsgkdsfjgkdfghiuuerhidsjdfgpshgpiwejgdspfhghpuewrihgdpioghewrughdfsiughperwuipigh",
				"sdfiughpwerspovignevmidpiogbjpvsmisdflkgjsdf;",
				"lgjpoijpofhspijvnspguhseoknfsvoisdfhgosidpfvnpsokdnbs - iobjvpkbnpsdfiogdsgndfpbibnbsiodjb[i",
				"gdfodfsn[b]]bondigshpbx ojgsrhgsvjgheirtiovsopimgp"
				"odfhbddvnpmzgksdcforitvgpmi gs,dgjdfknmgcsegx fmkbjdpog jdp,ogjd pmkosdkghvmcgcmpovsngmsgfgmgcplkbgfmgkmndpfgdpjghn fgjnpxjx bnfgh" };
			std::string sum = ArraySum(arr);
			CHECK(sum == "ddfgdfgsgkdsfjgkdfghiuuerhidsjdfgpshgpiwejgdspfhghpuewrihgdpioghewrughdfsiughperwuipighsdfiughpwerspovignevmidpiogbjpvsmisdflkgjsdf;"
				"lgjpoijpofhspijvnspguhseoknfsvoisdfhgosidpfvnpsokdnbs - iobjvpkbnpsdfiogdsgndfpbibnbsiodjb[igdfodfsn[b]]bondigshpbx ojgsrhgsvjgheirtiovsopimgp"
				"odfhbddvnpmzgksdcforitvgpmi gs,dgjdfknmgcsegx fmkbjdpog jdp,ogjd pmkosdkghvmcgcmpovsngmsgfgmgcplkbgfmgkmndpfgdpjghn fgjnpxjx bnfgh");
		}
	}
}

SCENARIO("Checking the correct operation when passing an empty vector")
{
	WHEN("int empty")
	{
		THEN("Return 0")
		{
			std::vector<int> arr{ };
			int sum = ArraySum(arr);
			CHECK(sum == 0);
		}
	}

	WHEN("float empty")
	{
		THEN("Return 0")
		{
			std::vector<float> arr{ };
			float sum = ArraySum(arr);
			CHECK(sum == 0);
		}
	}

	WHEN("double empty")
	{
		THEN("Return 0")
		{
			std::vector<double> arr{ };
			double sum = ArraySum(arr);
			CHECK(sum == 0);
		}
	}

	WHEN("string empty")
	{
		THEN("Return empty string")
		{
			std::vector<std::string> arr{ };
			std::string sum = ArraySum(arr);
			CHECK(sum == "");
		}
	}
}