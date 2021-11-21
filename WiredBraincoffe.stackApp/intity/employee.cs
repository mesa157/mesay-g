namespace WiredBraincoffe.stackApp.intity
{
    class Employee
    {
        public int ID { get; set; }
        public string FristName { get; set; }

        public string String() => $"ID: {ID}  , FristName {FristName}";

    }
}
