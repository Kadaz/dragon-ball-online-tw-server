CNtlTSTrigger
{
	sm = 1;
	sq = 0;
	qc = 23;
	rq = 0;
	tid = 6905;
	title = 690502;

	CNtlTSGroup
	{
		gid = 0;

		CDboTSContGAct
		{
			cid = 2;
			elnk = 255;
			nextlnk = 254;
			prelnk = "1;";

			CDboTSActOutMsg
			{
				idx = 116;
				taid = 1;
			}
		}
		CDboTSContEnd
		{
			cid = 254;
			prelnk = "2;";
			type = 1;
		}
		CDboTSContGAct
		{
			cid = 1;
			elnk = 255;
			nextlnk = 2;
			prelnk = "0;";

			CDboTSActMail
			{
				dtidx = 2007;
				itidx = -1;
				stidx = 2006;
				icnt = 255;
				taid = 1;
				zenny = -1;
			}
		}
		CDboTSContStart
		{
			cid = 0;
			stdiag = 690507;
			nolnk = 255;
			rm = 0;
			yeslnk = 1;

			CDboTSLevelCheck
			{
			}
			CDboTSCheckLvl
			{
				maxlvl = 100;
				minlvl = 40;
			}
			CDboTSCheckClrQst
			{
				and = "6888;";
				flink = 0;
				not = 0;
			}
		}
	}
}

