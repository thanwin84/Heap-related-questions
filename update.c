void delete_Record(void)
{
    FILE *oldRecord,*newRecord;
    // keep track of how many records have been deleted
    int records =0;
    // Reading record.dat file
    oldRecord=fopen("record.dat","r");
    // creating a new file named new.dat
    newRecord = fopen("new.dat","w");
    printf("Enter the account no. of the customer you want to delete: ");
    scanf("%d",&rem.acc_no);
    while (fscanf(oldRecord,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        // All the records are being copied to new file named new.dat except the deleted one
        if(add.acc_no!=rem.acc_no)
            fprintf(newRecord,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

        else
            {
                records++;
                printf("\nRecord has been deleted successfully!\n");
            }
   }
   fclose(oldRecord);
   fclose(newRecord);

   remove("record.dat");
   rename("new.dat","record.dat");

   if(records == 0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
            printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
            scanf("%d",&main_exit);

            if (main_exit==1)
                menu();

            else if (main_exit==2)
                close();

            else if(main_exit==0)
                delete_Record();

            else
                {
                    printf("\nInvalid!\a");
                    goto erase_invalid;
                }
        }
    else
        {
            printf("\nEnter 1 to go to the main menu or 0 to exit: ");
            scanf("%d",&main_exit);
            system("cls");

            if (main_exit==1)
                menu();
            else
                close();
            }

}
