CNtlTSTrigger
{
	sm = 1;
	sq = 1;
	qc = 0;
	rq = 0;
	tid = 14;
	title = 1402;

	CNtlTSGroup
	{
		gid = 0;

		CDboTSContGAct
		{
			cid = 2;
			elnk = 252;
			nextlnk = 100;
			prelnk = "1;";

			CDboTSActNPCConv
			{
				conv = 1409;
				ctype = 1;
				idx = 5312101;
				taid = 2;
			}
			CDboTSActRegQInfo
			{
				cont = 1408;
				gtype = 1;
				area = 1401;
				goal = 1404;
				grade = 132203;
				rwd = 100;
				scitem = -1;
				sort = 1405;
				stype = 1;
				taid = 1;
				title = 1402;
			}
		}
		CDboTSContStart
		{
			cid = 0;
			stdiag = 1407;
			nolnk = 253;
			rm = 0;
			yeslnk = 1;

			CDboTSCheckPCRace
			{
				raceflg = 1;
			}
			CDboTSCheckLvl
			{
				maxlvl = 100;
				minlvl = 3;
			}
			CDboTSClickNPC
			{
				npcidx = "5312101;";
			}
			CDboTSCheckClrQst
			{
				flink = 1;
				flinknextqid = "15;";
				not = 0;
			}
		}
		CDboTSContEnd
		{
			cid = 253;
			prelnk = "0;1;252;";
			type = 0;
		}
		CDboTSContProposal
		{
			cancellnk = 253;
			cid = 1;
			cont = 1408;
			gtype = 1;
			oklnk = 2;
			area = 1401;
			goal = 1404;
			sort = 1405;
			prelnk = "0;";
			ds = 1;
			grade = 132203;
			rwd = 100;
			title = 1402;
		}
		CDboTSContEnd
		{
			cid = 254;
			prelnk = "100;";
			type = 1;
		}
		CDboTSContGAct
		{
			cid = 252;
			elnk = 255;
			nextlnk = 253;
			prelnk = "2;";
		}
		CDboTSContReward
		{
			canclnk = 255;
			cid = 100;
			rwdzeny = 0;
			desc = 1414;
			nextlnk = 254;
			rwdexp = 0;
			rwdtbl = 1401;
			rwdtype = 0;
			ltime = -1;
			prelnk = "2;";
			usetbl = 1;

			CDboTSClickNPC
			{
				npcidx = "5591202;";
			}
		}
	}
}

