CNtlTSTrigger
{
	sm = 1;
	sq = 1;
	qc = 6;
	rq = 0;
	tid = 1134;
	title = 113402;

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
				conv = 113409;
				ctype = 1;
				idx = 3147103;
				taid = 2;
			}
			CDboTSActRegQInfo
			{
				cont = 113408;
				gtype = 1;
				area = 113401;
				goal = 113404;
				grade = 132203;
				rwd = 100;
				scitem = -1;
				sort = 113405;
				stype = 1;
				taid = 1;
				title = 113402;
			}
		}
		CDboTSContProposal
		{
			cancellnk = 253;
			cid = 1;
			cont = 113408;
			gtype = 1;
			oklnk = 2;
			area = 113401;
			goal = 113404;
			sort = 113405;
			prelnk = "0;";
			ds = 1;
			grade = 132203;
			rwd = 100;
			title = 113402;
		}
		CDboTSContReward
		{
			canclnk = 255;
			cid = 100;
			rwdzeny = 0;
			desc = 113414;
			nextlnk = 254;
			rwdexp = 0;
			rwdtbl = 113401;
			rwdtype = 0;
			ltime = -1;
			prelnk = "2;";
			usetbl = 1;

			CDboTSClickNPC
			{
				npcidx = "5061302;";
			}
		}
		CDboTSContStart
		{
			cid = 0;
			stdiag = 113407;
			nolnk = 253;
			rm = 0;
			yeslnk = 1;

			CDboTSCheckLvl
			{
				maxlvl = 100;
				minlvl = 47;
			}
			CDboTSClickNPC
			{
				npcidx = "3147103;";
			}
		}
		CDboTSContEnd
		{
			cid = 253;
			prelnk = "0;1;252;";
			type = 0;
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
	}
}

